# Interfaz PS1

## Estado

- Estado actual: en depuracion de `ACK` / `DATA`.
- Objetivo: emular un control digital PS1 cableado desde ESP32.
- Compatibilidad PS2: aun no implementada. Primero se valida PS1 digital; PS2 queda como pendiente de investigacion/pruebas.

## Pines Rev 1.4 / V2

| Senal | GPIO ESP32 | Direccion | Descripcion |
|---|---:|---|---|
| PS1_DATA | GPIO19 | Salida | Mando hacia consola |
| PS1_CMD | GPIO23 | Entrada | Consola hacia mando |
| PS1_ATT | GPIO5 | Entrada | Seleccion / atencion de consola |
| PS1_CLK | GPIO18 | Entrada | Reloj de consola |
| PS1_ACK | GPIO4 | Salida | Pulso de acknowledge |

## Conector PS1

| Pin | Senal |
|---:|---|
| 1 | DATA |
| 2 | CMD |
| 3 | VIB_NC |
| 4 | GND |
| 5 | VCC_3V3 |
| 6 | ATT |
| 7 | CLK |
| 8 | NC |
| 9 | ACK |

## Deteccion de modo

| Condicion | Modo |
|---|---|
| PS1_ATT = LOW al arrancar | Modo PS1 |
| PS1_ATT = HIGH al arrancar | Modo Bluetooth |

## Protocolo digital base

| Byte | Valor | Descripcion |
|---:|---|---|
| 0 | 0xFF | Idle |
| 1 | 0x41 | Tipo: Digital Controller |
| 2 | 0x5A | Byte fijo |
| 3 | Botones 1 | Select / Start / D-Pad, 0 = presionado |
| 4 | Botones 2 | L2 / R2 / L1 / R1 / Triangulo / Circulo / Cruz / Cuadrado, 0 = presionado |

## Nota sobre PS2

Aunque PS1 y PS2 comparten conector y una base de comunicacion similar para controles, este proyecto todavia no declara compatibilidad PS2. Cualquier prueba en PS2 debe tratarse como experimental hasta validar handshake, timing, reconocimiento del control y comportamiento de botones.

## Plan de pruebas

1. Verificar alimentacion y GND comun con consola.
2. Capturar ATT, CLK, CMD, DATA y ACK con analizador logico.
3. Confirmar respuesta base `0x41 0x5A`.
4. Validar que DATA quede estable antes del flanco esperado de CLK.
5. Ajustar pulso ACK hasta que la consola reconozca el control.
6. Probar botones uno por uno.
7. Activar AutoFire y confirmar alternancia de 50 ms ON / 50 ms OFF.
8. Una vez PS1 sea estable, documentar pruebas PS2 por separado.

## Riesgos

- Timing estricto de ACK.
- Direccion de DATA y niveles electricos.
- Ruido o pull-up insuficiente en lineas de protocolo.
- PS2 puede requerir validaciones adicionales antes de considerarse soportado.
