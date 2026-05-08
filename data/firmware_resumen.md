# Resumen Firmware

## Detección de modo

| Condición | Modo | Descripción |
|---|---|---|
| PS1_ATT = LOW al arrancar | Modo PS1 | Consola PS1/PS2 activa — emulación SPI |
| PS1_ATT = HIGH al arrancar | Modo Bluetooth | Sin consola — HID Gamepad BLE |
| SW10 Placa_2 = OFF | Apagado | Sin alimentación desde batería |

## Lógica Turbo

| Condición GPIO | Duración | Comportamiento |
|---|---:|---|
| GPIO HIGH | — | Botón suelto — sin acción |
| GPIO LOW | < 150 ms | Pulsación normal del usuario |
| GPIO LOW continuo | > 150 ms | SW ON jalando a GND = TURBO activo |
| TURBO activo | 50 ms ON / 50 ms OFF | 10 pulsaciones por segundo |

## Protocolo PS1 SPI

| Byte | Valor | Descripción |
|---:|---|---|
| 0 | 0xFF | Idle |
| 1 | 0x41 | Tipo: Digital Controller |
| 2 | 0x5A | Fijo siempre |
| 3 | Botones 1 | Select/Start/D-Pad — 0=presionado |
| 4 | Botones 2 | L2/R2/L1/R1/△/○/×/□ — 0=presionado |
