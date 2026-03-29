# Git Auto-Sync — Instrucciones de instalación

## ¿Qué hace?
Cada 30 minutos, automáticamente:
1. **Baja** los cambios de GitHub (pull)
2. **Sube** tus cambios locales (add + commit + push)

Sin que tengas que hacer nada. Funciona en segundo plano.

---

## Archivos incluidos
| Archivo | Para qué sirve |
|---|---|
| `git-autosync.ps1` | El script que hace el pull + push |
| `instalar-autosync.ps1` | Instala la tarea automática en Windows |

---

## Instalación (hacer en AMBAS computadoras)

### Paso 1 — Verificar que tu carpeta ya tiene Git configurado
Abre PowerShell en tu carpeta `VSCODE` y ejecuta:
```
git status
git remote -v
```
Debes ver tu repositorio de GitHub en el remote `origin`. Si no, configúralo:
```
git remote add origin https://github.com/TU_USUARIO/TU_REPO.git
```

### Paso 2 — Editar el path en los scripts (si tu carpeta no es la default)
Abre `instalar-autosync.ps1` con el Bloc de Notas y cambia esta línea si es necesario:
```powershell
$RepoPath = "C:\Users\TU_USUARIO\VSCODE"
```

### Paso 3 — Instalar
1. Pon ambos archivos `.ps1` en la misma carpeta temporal (ej: Descargas)
2. Haz **click derecho** en `instalar-autosync.ps1`
3. Selecciona **"Ejecutar con PowerShell como administrador"**
4. Espera que termine — hará una primera sincronización automáticamente

### Paso 4 — Repetir en la otra computadora
Haz exactamente lo mismo en tu otra PC.

---

## Verificar que funciona
- Busca en el **Programador de Tareas** de Windows la tarea `GitAutoSync-VSCODE`
- Revisa el archivo `git-autosync.log` dentro de tu carpeta VSCODE

---

## Solución de problemas

**"No hay remote origin"**
→ Configura el remote: `git remote add origin https://github.com/TU_USUARIO/REPO.git`

**"Error de autenticación"**
→ Asegúrate de tener configurado Git con token o SSH:
`git config --global credential.helper manager`

**Conflictos de merge**
→ El script usa `pull --rebase`. Si hay conflicto, resuélvelo manualmente y haz commit.
→ Evita editar el mismo archivo en ambas PCs al mismo tiempo.

**Ejecutar manualmente (para probar)**
```powershell
powershell -ExecutionPolicy Bypass -File "C:\Users\TU_USUARIO\VSCODE\git-autosync.ps1"
```

---

## Desinstalar
```powershell
Unregister-ScheduledTask -TaskName "GitAutoSync-VSCODE" -Confirm:$false
```
