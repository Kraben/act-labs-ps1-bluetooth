# Arquitectura de interfaces

Esta carpeta separa la documentacion por interfaz de consola para que el proyecto pueda crecer mas alla de PS1 sin mezclar protocolos.

## Objetivo

Mantener una capa comun de lectura de botones y AutoFire, y una capa por consola que traduzca ese estado al protocolo requerido.

```text
Botones / D-Pad / AutoFire
        |
        v
Estado normalizado del control
        |
        +-- PS1 cableado
        +-- Bluetooth HID
        +-- SNES futuro
        +-- Genesis futuro
        +-- N64 futuro
        +-- GameCube futuro
```

## Capas propuestas

| Capa | Responsabilidad |
|---|---|
| Entrada fisica | Lee botones, D-Pad, START, SELECT y switches AutoFire |
| Estado normalizado | Guarda botones en formato comun activo en bajo o booleano interno |
| Motor AutoFire | Genera pulsos turbo por boton cuando aplica |
| Interfaz de salida | Convierte el estado normalizado a PS1, BLE HID, SNES, Genesis, etc. |
| Depuracion | Serial log y analizador logico por protocolo |

## Reglas de documentacion

Cada archivo de interfaz debe incluir:

1. Estado actual: operativo, en depuracion o futuro.
2. Pines usados.
3. Niveles electricos esperados.
4. Protocolo resumido.
5. Plan de pruebas.
6. Pendientes y riesgos.

## Estado de interfaces

| Interfaz | Archivo | Estado |
|---|---|---|
| PS1 | `ps1.md` | En depuracion ACK/DATA |
| SNES | `snes.md` | Futuro |
| Genesis | `genesis.md` | Futuro |
| N64 | `n64.md` | Futuro |
| GameCube | `gamecube.md` | Futuro |
