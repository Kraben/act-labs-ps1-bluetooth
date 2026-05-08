# AutoFire

## Concepto

Cada botón con AutoFire se conecta a un switch SPDT. El switch permite usar el botón en modo directo o forzar una condición de activación de turbo llevando la señal a GND.

## Mapeo de switches

| SW | Señal AF | Botón | JP1 Pin | GPIO ESP32 | Función | Notas |
|---|---|---|---:|---|---|---|
| SW1 | AF_L1 | L1 | 7 | GPIO27 | Turbo L1 | OFF=directo, ON=GND→Turbo |
| SW2 | AF_CRUZ | × Cruz | 8 | GPIO25 | Turbo × | OFF=directo, ON=GND→Turbo |
| SW3 | AF_CIRCULO | ○ Círculo | 7 | GPIO26 | Turbo ○ | OFF=directo, ON=GND→Turbo |
| SW4 | AF_L2 | L2 | 10 | GPIO32 | Turbo L2 | OFF=directo, ON=GND→Turbo |
| SW5 | AF_R1 | R1 | 8 | GPIO33 | Turbo R1 | OFF=directo, ON=GND→Turbo |
| SW6 | AF_CUADRADO | □ Cuadrado | 4 | GPIO12 | Turbo □ | OFF=directo, ON=GND→Turbo |
| SW7 | AF_TRIANGULO | △ Triángulo | 6 | GPIO14 | Turbo △ | OFF=directo, ON=GND→Turbo |
| SW8 | AF_R2 | R2 | 3 | GPIO13 | Turbo R2 | OFF=directo, ON=GND→Turbo |
| SW9 | AF_MODE | MODE | 2 | GPIO15 | Modo AF global | Reservado para uso futuro |
| SW10 | BATT_FROM_TP | — | 12 | VIN | Encendido BT | ON=alimenta ESP32 desde batería |

## Lógica sugerida

| Condición GPIO | Duración | Comportamiento |
|---|---:|---|
| HIGH | — | Botón suelto |
| LOW | < 150 ms | Pulsación normal |
| LOW continuo | > 150 ms | Turbo activo |
| Turbo activo | 50 ms ON / 50 ms OFF | 10 pulsaciones por segundo |

## Consideraciones

- Confirmar que todos los botones estén en lógica activa LOW.
- Aplicar debounce por software.
- Separar la lectura física del botón y el estado virtual enviado al protocolo PS1/BLE.
- Guardar un flag por botón: `physical_pressed`, `turbo_enabled`, `virtual_pressed`.
