# Interfaz Genesis / Mega Drive

## Estado

- Estado actual: futuro.
- Objetivo: evaluar una posible interfaz cableada para Sega Genesis / Mega Drive.

## Alcance inicial

Esta interfaz aun no esta implementada. Se documenta como posible expansion futura para separar investigacion, pinout y firmware por consola.

## Datos por investigar

| Tema | Pendiente |
|---|---|
| Protocolo | Confirmar lectura multiplexada de botones |
| Niveles electricos | Confirmar compatibilidad con ESP32 y necesidad de level shifting |
| Pines | Definir mapeo seguro |
| Conector | Documentar DB9 / pinout real |
| Firmware | Definir modulo independiente de PS1/BLE |

## Propuesta de integracion

La interfaz Genesis debe partir del estado normalizado de botones del proyecto.

```text
Estado normalizado de botones -> codificador Genesis -> lineas Genesis
```

## Pendientes

1. Documentar pinout Genesis DB9.
2. Definir botones soportados: 3 botones o 6 botones.
3. Validar niveles electricos.
4. Crear firmware de prueba separado.
