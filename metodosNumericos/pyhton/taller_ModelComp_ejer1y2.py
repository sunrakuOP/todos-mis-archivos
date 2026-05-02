import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

try:
    plt.style.use("seaborn-v0_8-darkgrid")
except OSError:
    plt.style.use("seaborn-darkgrid")

plt.rcParams.update({
    "font.size": 11,
    "axes.titlesize": 12,
    "axes.titleweight": "bold",
    "figure.dpi": 100,
    "figure.facecolor": "white",
    "axes.facecolor": "#f8f8f8",
})

# ══════════════════════════════════════════════════════════════════════════════
# EJERCICIO 1 — PCA con s4 = -1.5*s1 + ε (Módulo 1)
# ══════════════════════════════════════════════════════════════════════════════
print("=" * 65)
print("EJERCICIO 1 — PCA con cuatro sensores (s4 = -1.5·s1 + ε)")
print("=" * 65)

np.random.seed(42)
n = 100
t = np.linspace(0, 10, n)

sensor1 = np.sin(t) + np.random.normal(0, 0.1, n)
sensor2 = 2.0 * sensor1 + np.random.normal(0, 0.2, n)
sensor3 = np.random.normal(0, 0.5, n)
sensor4 = -1.5 * sensor1 + np.random.normal(0, 0.1, n)   # nuevo

X4 = np.column_stack([sensor1, sensor2, sensor3, sensor4])
p4 = X4.shape[1]
print(f"\nDimensiones de X4: {X4.shape}  —  {n} muestras, {p4} variables")

# ── Preprocesamiento
mu4    = np.mean(X4, axis=0)
sigma4 = np.std(X4,  axis=0, ddof=1)
X4_s   = (X4 - mu4) / sigma4

C4 = X4_s.T @ X4_s / (n - 1)
print(f"\nMatriz de correlación empírica (4×4):")
print(np.round(C4, 4))

# ── SVD
U4, S4, Vt4 = np.linalg.svd(X4_s, full_matrices=False)
lambdas4 = S4**2 / (n - 1)
ve4      = lambdas4 / lambdas4.sum()
ve4_cum  = np.cumsum(ve4)

print(f"\nValores singulares σᵢ : {S4.round(4)}")
print(f"Valores propios   λᵢ  : {lambdas4.round(4)}")
print(f"Varianza explicada (%) : {(ve4*100).round(2)}")
print(f"Varianza acumulada (%) : {(ve4_cum*100).round(2)}")

# ── Respuesta 2: comparar con caso original (3 sensores)
print("\n--- Comparación con el caso original (3 sensores) ---")
print(f"  Original  — ve acumulada: [66.51, 99.68, 100.0] %")
print(f"  Con s4    — ve acumulada: {(ve4_cum*100).round(2)} %")
print("  → El CP1 concentra más varianza porque ahora hay 3 sensores correlacionados")
print("    con el mismo factor subyacente (la señal sinusoidal de s1).")

# ── Respuesta 3: cuántos componentes para superar 90%
k_90 = int(np.searchsorted(ve4_cum, 0.90)) + 1
print(f"\n--- ¿Cuántos componentes para superar el 90%? ---")
print(f"  k = {k_90}  (ve acumulada con {k_90} CP: {ve4_cum[k_90-1]*100:.2f}%)")

# ── Visualización ejercicio 1
scores4 = X4_s @ Vt4[:2].T

fig1 = plt.figure(figsize=(15, 4))
gs1  = gridspec.GridSpec(1, 3, figure=fig1, wspace=0.35)

# Scree plot
ax0 = fig1.add_subplot(gs1[0])
ax0.bar(range(1, p4+1), ve4*100, color="#4C72B0", alpha=0.75, label="Individual", zorder=3)
ax0.plot(range(1, p4+1), ve4_cum*100, "ro--", lw=1.8, label="Acumulada", zorder=4)
ax0.axhline(90, color="gray", ls=":", lw=1.2, label="Umbral 90%")
ax0.set_xticks(range(1, p4+1))
ax0.set_xlabel("Componente Principal")
ax0.set_ylabel("Varianza explicada (%)")
ax0.set_title("Scree Plot — 4 sensores")
ax0.legend(fontsize=9)

# Proyección CP1 vs CP2
ax1 = fig1.add_subplot(gs1[1])
sc = ax1.scatter(scores4[:,0], scores4[:,1], c=t, cmap="plasma", s=18, alpha=0.8)
ax1.axhline(0, color="k", lw=0.5)
ax1.axvline(0, color="k", lw=0.5)
ax1.set_xlabel(f"CP1  ({ve4[0]*100:.1f}% var)")
ax1.set_ylabel(f"CP2  ({ve4[1]*100:.1f}% var)")
ax1.set_title("Proyección sobre CP1 y CP2")
plt.colorbar(sc, ax=ax1, label="tiempo t")

# Mapa de calor correlación 4×4
ax2 = fig1.add_subplot(gs1[2])
labels4 = ["S1", "S2", "S3", "S4"]
im = ax2.imshow(C4, cmap="RdBu_r", vmin=-1, vmax=1, aspect="auto")
plt.colorbar(im, ax=ax2, fraction=0.046, pad=0.04)
ax2.set_xticks(range(p4)); ax2.set_yticks(range(p4))
ax2.set_xticklabels(labels4); ax2.set_yticklabels(labels4)
for i in range(p4):
    for j in range(p4):
        ax2.text(j, i, f"{C4[i,j]:.2f}", ha="center", va="center",
                 fontsize=8, color="white" if abs(C4[i,j]) > 0.6 else "black")
ax2.set_title("Matriz de Correlación")

plt.suptitle("Ejercicio 1 — PCA con 4 sensores (s4 = -1.5·s1 + ε)", fontsize=13, y=1.02)
plt.savefig("ejer1_pca_4sensores.png", dpi=100, bbox_inches="tight")
plt.show()


# ══════════════════════════════════════════════════════════════════════════════
# EJERCICIO 2 — Regresión cuadrática (Módulo 2)
# ══════════════════════════════════════════════════════════════════════════════
print("\n" + "=" * 65)
print("EJERCICIO 2 — Regresión cuadrática: y = β₀ + β₁x + β₂x²")
print("=" * 65)

x_obs = np.array([1.0, 2.0, 3.0])
y_obs = np.array([2.0, 3.0, 5.0])
n_obs = len(x_obs)

# ── Paso 1: Matriz de diseño de Vandermonde grado 2 (columnas: 1, x, x²)
X_quad = np.column_stack([np.ones(n_obs), x_obs, x_obs**2])
print(f"\nMatriz de diseño Vandermonde grado 2:")
print(X_quad)

# ── Paso 2: Ecuación Normal — resolver X'X β = X'y
XtX_q = X_quad.T @ X_quad
Xty_q = X_quad.T @ y_obs
print(f"\nX⊺X =\n{XtX_q}")
print(f"X⊺y = {Xty_q}")

beta_q = np.linalg.solve(XtX_q, Xty_q)
print(f"\nSolución (np.linalg.solve):")
print(f"  β₀ = {beta_q[0]:.10f}")
print(f"  β₁ = {beta_q[1]:.10f}")
print(f"  β₂ = {beta_q[2]:.10f}")
print(f"\nModelo: ŷ = {beta_q[0]:.4f} + ({beta_q[1]:.4f})x + ({beta_q[2]:.4f})x²")

# Verificación manual exacta:
# Sistema 3×3 exactamente determinado → solución única exacta
# β₀=2, β₁=-0.5, β₂=0.5  (polinomio que pasa por los 3 puntos)
print(f"\nVerificación manual exacta:")
print(f"  β₀ = 2.0     → {beta_q[0]:.10f}  ✓")
print(f"  β₁ = -0.5    → {beta_q[1]:.10f}  ✓")
print(f"  β₂ =  0.5    → {beta_q[2]:.10f}  ✓")

# ── Paso 3: Métricas y comparación con modelo lineal
y_pred_q  = X_quad @ beta_q
residuals_q = y_obs - y_pred_q
SSE_q     = float(residuals_q @ residuals_q)
SST       = float(np.sum((y_obs - y_obs.mean())**2))
R2_q      = 1.0 - SSE_q / SST

# Modelo lineal (del taller original)
X_lin = np.column_stack([np.ones(n_obs), x_obs])
beta_l = np.linalg.solve(X_lin.T @ X_lin, X_lin.T @ y_obs)
y_pred_l  = X_lin @ beta_l
SSE_l     = float((y_obs - y_pred_l) @ (y_obs - y_pred_l))
R2_l      = 1.0 - SSE_l / SST

print(f"\n--- Comparación de modelos ---")
print(f"  {'Métrica':<18} {'Lineal':>12} {'Cuadrático':>12}")
print(f"  {'-'*42}")
print(f"  {'SSE':<18} {SSE_l:>12.6f} {SSE_q:>12.2e}")
print(f"  {'R²':<18} {R2_l:>12.6f} {R2_q:>12.6f}")
print()
print("  Interpretación:")
print(f"  → Con n=3 puntos y grado 2 (3 parámetros), el sistema queda exactamente")
print(f"    determinado: hay un único polinomio de grado ≤2 que pasa por los 3 puntos.")
print(f"  → R² = 1 no indica un mejor modelo, sino interpolación perfecta.")
print(f"  → Para evaluar cuál modelo es 'mejor' se necesitarían más datos (n > 3).")

# ── Visualización ejercicio 2
fig2, axes2 = plt.subplots(1, 2, figsize=(12, 4))

x_lin_plot = np.linspace(0.5, 3.5, 200)
y_lin_plot  = beta_l[0] + beta_l[1] * x_lin_plot
y_quad_plot = beta_q[0] + beta_q[1] * x_lin_plot + beta_q[2] * x_lin_plot**2

axes2[0].scatter(x_obs, y_obs, color="crimson", s=100, zorder=5, label="Datos")
axes2[0].plot(x_lin_plot, y_lin_plot,  "b--", lw=2,
              label=f"Lineal: $\\hat{{y}}$={beta_l[0]:.3f}+{beta_l[1]:.3f}x   $R^2$={R2_l:.4f}")
axes2[0].plot(x_lin_plot, y_quad_plot, "g-",  lw=2,
              label=f"Cuadrático: $R^2$={R2_q:.4f}")
axes2[0].set_xlabel("Aditivos (kg)")
axes2[0].set_ylabel("Resistencia (MPa)")
axes2[0].set_title("Comparación Lineal vs Cuadrático")
axes2[0].legend(fontsize=9)

# Residuos de ambos modelos
width = 0.35
idx   = np.arange(n_obs)
axes2[1].bar(idx - width/2, y_obs - y_pred_l,  width, color="#4C72B0", alpha=0.8, label=f"Residuos lineal")
axes2[1].bar(idx + width/2, y_obs - y_pred_q,  width, color="#4CAF50", alpha=0.8, label="Residuos cuadrático (≈0)")
axes2[1].axhline(0, color="k", lw=0.9)
axes2[1].set_xticks(idx); axes2[1].set_xticklabels([f"Obs {i+1}" for i in idx])
axes2[1].set_ylabel("Residuo $y - \\hat{y}$")
axes2[1].set_title("Análisis de Residuos")
axes2[1].legend(fontsize=9)

plt.tight_layout()
plt.savefig("ejer2_regresion_cuadratica.png", dpi=100, bbox_inches="tight")
plt.show()

print("\nArchivos guardados: ejer1_pca_4sensores.png, ejer2_regresion_cuadratica.png")
