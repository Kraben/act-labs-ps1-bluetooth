# Interfaz SNES

## Estado

- Estado actual: futuro.
- Objetivo: documentar una posible interfaz cableada para Super Nintendo.

## Alcance inicial

Esta interfaz aun no esta implementada. La idea es reservar el espacio de documentacion para evaluar pines, niveles electricos, protocolo y viabilidad antes de modificar hardware.

## Datos por investigar

| Tema | Pendiente |
|---|---|
| Protocolo | Confirmar secuencia de latch / clock / data |
| Niveles electricos | Confirmar tolerancia de entrada/salida con ESP32 |
| Pines | Definir mapeo seguro |
| Firmware | Definir modulo independiente de PS1 |
| Conector | Documentar pinout real antes de fabricar |

## Propuesta de integracion

La interfaz SNES debe consumir el mismo estado normalizado de botones usado por PS1/BLE. No debe duplicar la logica de lectura fisica ni AutoFire.

```text
Estado normalizado de botones -> codificador SNES -> lineas SNES
```

## Pendientes

1. Documentar pinout del conector SNES.
2. Confirmar si requiere 5 V y si se necesita level shifting.
3. Definir si el ESP32 puede manejar el timing directamente.
4. Crear sketch de prueba aislado antes de mezclarlo con el firmware principal.
