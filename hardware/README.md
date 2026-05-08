# Hardware

Esta carpeta contiene exportaciones PDF e imágenes usadas como referencia del diseño.

## PDFs

- `ACT_Labs_REX.pdf`: esquemático principal de conversión de tablero PS1.
- `ArcLabsPCB.pdf`: vista de PCB principal.
- `AutoFire.pdf`: esquemático de la placa AutoFire.
- `AutoFirePCB.pdf`: vista de PCB AutoFire.

## Imágenes

- `Led-Switch.png`: detalle de LED / switch de encendido.
- `Partcial_SCHM.png`: captura parcial del esquemático principal.
- `SW_part.png`: captura de la placa de switches AutoFire.

## Validaciones recomendadas

- Verificar continuidad de GND entre placas.
- Confirmar orientación del diodo SS14.
- Confirmar que `BATT_FROM_TP` entra a `VIN` y no a `3V3`.
- Confirmar que GPIO34/35/36/39 tengan pull-ups externos reales.
