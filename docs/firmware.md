# Firmware

## Objetivo

Implementar un firmware para ESP32 con dos modos de operación:

- **Modo PS1**: emulación de control digital PS1.
- **Modo Bluetooth**: gamepad HID BLE.

## Detección de modo

| Condición | Modo | Descripción |
|---|---|---|
| `PS1_ATT = LOW` al arrancar | PS1 | Consola PS1/PS2 activa; emulación SPI |
| `PS1_ATT = HIGH` al arrancar | Bluetooth | Sin consola; HID Gamepad BLE |
| `SW10 = OFF` | Apagado | Sin alimentación desde batería |

## Protocolo PS1 digital

| Byte | Valor | Descripción |
|---:|---|---|
| 0 | `0xFF` | Idle |
| 1 | `0x41` | Tipo: Digital Controller |
| 2 | `0x5A` | Fijo |
| 3 | Botones 1 | Select/Start/D-Pad; `0=presionado` |
| 4 | Botones 2 | L2/R2/L1/R1/△/○/×/□; `0=presionado` |

## Plan de implementación

1. Definir constantes de pines.
2. Inicializar pines con `INPUT_PULLUP` excepto GPIO34/35/36/39, que requieren resistencias externas.
3. Implementar lectura de botones con debounce.
4. Implementar motor AutoFire por botón.
5. Implementar modo PS1.
6. Implementar modo BLE HID.
7. Agregar pruebas de lectura serial.

## Estado del archivo `.ino`

El archivo `firmware/ACT_Labs_Controller/ACT_Labs_Controller.ino` es una plantilla documentada para iniciar el desarrollo. Todavía requiere completar las rutinas específicas de PS1 SPI y BLE HID según la librería elegida.
