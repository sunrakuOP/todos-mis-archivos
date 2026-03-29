# ============================================================
#  git-autosync.ps1
#  Auto-sincroniza tu carpeta VSCODE con GitHub cada 30 min
#  Haz pull primero, luego push de tus cambios
# ============================================================

param(
    [string]$RepoPath = ""
)

# --- CONFIGURACION ---
# Si no se pasa el path como argumento, usar el valor de abajo
if ($RepoPath -eq "") {
    $RepoPath = "C:\Users\juann\OneDrive\Documents\VSCODE"   # <-- Cambia esto si tu carpeta está en otro lugar
}

$LogFile = "$RepoPath\git-autosync.log"

# ---- Funciones ----
function Write-Log {
    param([string]$Message)
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $line = "[$timestamp] $Message"
    Write-Host $line
    Add-Content -Path $LogFile -Value $line
}

function Invoke-Git {
    param([string]$Arguments)
    $result = & git -C $RepoPath $Arguments.Split(" ") 2>&1
    return $result
}

# ---- Verificaciones iniciales ----
if (-not (Test-Path $RepoPath)) {
    Write-Log "ERROR: La carpeta '$RepoPath' no existe."
    exit 1
}

if (-not (Test-Path "$RepoPath\.git")) {
    Write-Log "ERROR: '$RepoPath' no es un repositorio Git. Ejecuta 'git init' primero."
    exit 1
}

Set-Location $RepoPath
Write-Log "=== Iniciando sync de: $RepoPath ==="

# ---- 1. Verificar si hay rama remota configurada ----
$remote = & git -C $RepoPath remote 2>&1
if ($remote -notmatch "origin") {
    Write-Log "ERROR: No hay remote 'origin' configurado. Agrega tu repositorio con: git remote add origin <URL>"
    exit 1
}

# ---- 2. PULL (bajar cambios del servidor) ----
Write-Log "Haciendo PULL..."
$pullResult = & git -C $RepoPath pull --rebase origin (& git -C $RepoPath branch --show-current 2>&1) 2>&1
Write-Log "Pull resultado: $pullResult"

if ($LASTEXITCODE -ne 0) {
    Write-Log "ADVERTENCIA: Pull tuvo conflictos o error. Revisa manualmente."
    # No salir, intentar el push de todas formas para no perder cambios locales
}

# ---- 3. Verificar si hay cambios locales ----
$status = & git -C $RepoPath status --porcelain 2>&1

if ($status) {
    Write-Log "Cambios detectados. Haciendo ADD + COMMIT + PUSH..."

    # ADD todos los cambios
    & git -C $RepoPath add -A 2>&1 | Out-Null

    # COMMIT con timestamp automatico
    $commitMsg = "auto-sync: $(Get-Date -Format 'yyyy-MM-dd HH:mm')"
    $commitResult = & git -C $RepoPath commit -m $commitMsg 2>&1
    Write-Log "Commit: $commitResult"

    # PUSH
    $pushResult = & git -C $RepoPath push origin (& git -C $RepoPath branch --show-current 2>&1) 2>&1
    Write-Log "Push resultado: $pushResult"

    if ($LASTEXITCODE -eq 0) {
        Write-Log "SUCCESS: Cambios subidos correctamente."
    } else {
        Write-Log "ERROR en push: $pushResult"
    }
} else {
    Write-Log "Sin cambios locales. Nada que subir."
}

Write-Log "=== Sync completado ==="
Write-Log ""
