# Arquitectura V2

## Descripción general

El proyecto convierte un tablero ACT-LABS / PS1 en un control híbrido con dos modos de operación:

- **BLE HID**: gamepad Bluetooth usando ESP32.
- **PS1 cableado**: emulación de control digital PS1 usando las líneas `DATA`, `CMD`, `ATT`, `CLK` y `ACK`.

## Bloques principales

| Bloque | Función |
|---|---|
| ESP32 DevKit V1 | Lectura de botones, lógica AutoFire, BLE HID y emulación PS1 |
| TP4056 externo | Carga/protección de batería 3.7 V |
| Batería PS Vita 3.7 V | Alimentación portátil para modo Bluetooth |
| LD1117-3.3 | Regulación a 3.3 V para lógica |
| Diodo Schottky D1 | Protección/aislamiento de alimentación |
| Placa AutoFire | Switches SPDT para turbo por botón y encendido |
| Conector PS1 | Interfaz cableada con consola PS1/PS2 |

## Alimentación

La alimentación V2 queda documentada así:

1. La batería PS Vita entra al módulo TP4056.
2. `OUT+` del TP4056 se conecta a `BATT_FROM_TP`.
3. `OUT-` del TP4056 va a `GND`.
4. `BATT_FROM_TP` se conmuta desde `SW10` para alimentar el modo Bluetooth.
5. La placa incluye LD1117-3.3 para obtener `VCC_3V3`.
6. D1 usa diodo Schottky, con opción SS14 / 1N5817 según disponibilidad.

## Interfaz PS1

| Señal | GPIO ESP32 | Rol |
|---|---:|---|
| DATA | 19 | Mando -> consola |
| CMD | 23 | Consola -> mando |
| ATT | 5 | Selección / atención de consola |
| CLK | 18 | Reloj de consola |
| ACK | 4 | Pulso de acknowledge del mando |

El protocolo PS1 sigue en depuración, específicamente en la temporización de `ACK` y la estabilidad de `DATA`.

## Estado

| Área | Estado |
|---|---|
| Hardware | V2 / PCB V2.2 |
| BLE | Operativo |
| PS1 | En depuración de protocolo |
| KiCad | Archivos fuente y exportaciones BOM/POS recibidos |

## Notas de validación

- Confirmar pull-ups de `DATA` y `ACK` con R6/R7 de 4.7 kΩ.
- Verificar continuidad de GND entre placa principal, AutoFire y TP4056.
- Validar orientación de los diodos Schottky D1/D3.
- Confirmar que `BATT_FROM_TP` no alimente directamente `3V3`.
