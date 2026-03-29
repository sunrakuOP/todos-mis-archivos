# ============================================================
#  instalar-autosync.ps1
#  Registra git-autosync.ps1 en el Programador de Tareas
#  de Windows para que corra cada 30 minutos
#
#  EJECUTAR COMO ADMINISTRADOR
# ============================================================

# ---- CONFIGURACION - CAMBIA ESTOS VALORES ----
$RepoPath    = "C:\Users\juann\OneDrive\Documents\VSCODE"   # Ruta a tu carpeta VSCODE
$ScriptPath  = "$RepoPath\git-autosync.ps1"       # Donde copiaremos el script
$TaskName    = "GitAutoSync-VSCODE"
$IntervalMin = 30                                  # Cada cuantos minutos sincronizar

# ---- Verificar que se ejecuta como Admin ----
$isAdmin = ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
if (-not $isAdmin) {
    Write-Host "ERROR: Ejecuta este script como Administrador (click derecho -> Ejecutar como administrador)" -ForegroundColor Red
    pause
    exit 1
}

# ---- Verificar que la carpeta existe ----
if (-not (Test-Path $RepoPath)) {
    Write-Host "ERROR: La carpeta '$RepoPath' no existe." -ForegroundColor Red
    Write-Host "Edita este archivo y cambia la variable `$RepoPath a la ruta correcta." -ForegroundColor Yellow
    pause
    exit 1
}

# ---- Copiar git-autosync.ps1 a la carpeta del repo ----
$sourceScript = Join-Path (Split-Path $MyInvocation.MyCommand.Path) "git-autosync.ps1"
if (Test-Path $sourceScript) {
    Copy-Item $sourceScript $ScriptPath -Force
    Write-Host "Script copiado a: $ScriptPath" -ForegroundColor Green
} elseif (-not (Test-Path $ScriptPath)) {
    Write-Host "ERROR: No se encontro git-autosync.ps1. Asegurate de tener ambos archivos en la misma carpeta." -ForegroundColor Red
    pause
    exit 1
}

# ---- Crear la tarea programada ----
Write-Host "Configurando tarea programada '$TaskName'..." -ForegroundColor Cyan

# Eliminar si ya existe
if (Get-ScheduledTask -TaskName $TaskName -ErrorAction SilentlyContinue) {
    Unregister-ScheduledTask -TaskName $TaskName -Confirm:$false
    Write-Host "Tarea anterior eliminada." -ForegroundColor Yellow
}

# Accion: ejecutar PowerShell con el script
$action = New-ScheduledTaskAction `
    -Execute "powershell.exe" `
    -Argument "-NonInteractive -WindowStyle Hidden -ExecutionPolicy Bypass -File `"$ScriptPath`" -RepoPath `"$RepoPath`""

# Disparador: al iniciar sesion, luego repetir cada X minutos, indefinidamente
$trigger = New-ScheduledTaskTrigger -AtLogOn
$trigger.RepetitionInterval = [TimeSpan]::FromMinutes($IntervalMin)
$trigger.RepetitionDuration  = [TimeSpan]::MaxValue

# Configuracion: correr aunque no haya red inmediatamente, no pedir contrasena
$settings = New-ScheduledTaskSettingsSet `
    -ExecutionTimeLimit ([TimeSpan]::FromMinutes(5)) `
    -StartWhenAvailable `
    -RunOnlyIfNetworkAvailable

# Registrar con el usuario actual
$principal = New-ScheduledTaskPrincipal -UserId $env:USERNAME -LogonType Interactive -RunLevel Limited

Register-ScheduledTask `
    -TaskName $TaskName `
    -Action $action `
    -Trigger $trigger `
    -Settings $settings `
    -Principal $principal `
    -Description "Auto-sincroniza la carpeta VSCODE con GitHub cada $IntervalMin minutos" `
    | Out-Null

Write-Host ""
Write-Host "=====================================================" -ForegroundColor Green
Write-Host " INSTALACION COMPLETADA" -ForegroundColor Green
Write-Host "=====================================================" -ForegroundColor Green
Write-Host " Tarea: $TaskName" -ForegroundColor White
Write-Host " Carpeta: $RepoPath" -ForegroundColor White
Write-Host " Frecuencia: cada $IntervalMin minutos" -ForegroundColor White
Write-Host " Log: $RepoPath\git-autosync.log" -ForegroundColor White
Write-Host ""
Write-Host "Para desinstalar, ejecuta: Unregister-ScheduledTask -TaskName '$TaskName' -Confirm:`$false" -ForegroundColor Gray
Write-Host ""

# Ejecutar una primera vez ahora
Write-Host "Ejecutando primera sincronizacion ahora..." -ForegroundColor Cyan
& powershell.exe -NonInteractive -ExecutionPolicy Bypass -File $ScriptPath -RepoPath $RepoPath

pause
