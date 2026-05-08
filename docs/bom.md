# BOM preliminar

> Lista preliminar derivada de los esquemáticos. Validar contra KiCad antes de fabricar.

| Ref | Valor / parte | Descripción |
|---|---|---|
| U1 | ESP32 DevKit | Controlador principal |
| R1 | 1 kΩ | Pull-up / limitación en PS1_DATA hacia 3V3 |
| R2, R3, R4, R5 | 10 kΩ | Pull-up externos para entradas del D-Pad en GPIO input-only |
| R6, R7 | 15 kΩ | Pull-up START / SELECT |
| C1 | 220 µF | Capacitor de filtrado en VCC_3V3 |
| C2 | 100 nF | Desacoplo local |
| D1 | SS14 | Diodo Schottky de protección/aislamiento |
| START1, SELECT1 | SW_Push_Dual | Pulsadores duales |
| SW1–SW10 | SPDT | Switches AutoFire / encendido |
| H1–H4 | TP4056 pads | OUT+, BATT+, BATT-, GND |
| J1 | 1x13 | Puente AutoFire |
| J2 | 1x8 | Botonera frontal |
| J3 | 1x8 | Palanca direccional |
| J4 | 1x8 | Botones laterales |
| PS1_Connector1 | 1x9 | Conector PS1 |
