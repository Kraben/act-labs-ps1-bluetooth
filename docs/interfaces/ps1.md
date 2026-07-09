# Interfaz PS1

## Estado

- Firmware PS1 publico: actualizado para el alcance ACT Labs REX / PS1.
- Objetivo publico: emular un control digital PS1 cableado desde ESP32.
- Protocolo PS2 / DualShock: listo en la build Hybrid AUTO de apoyo/donativos.
- Firmware hibrido PS1/PS2/BLE: listo en la build Hybrid AUTO, no publicado como codigo fuente completo en este repositorio publico.

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

## Deteccion de modo publico

| Condicion | Modo |
|---|---|
| PS1_ATT = LOW al arrancar | Modo PS1 |
| PS1_ATT = HIGH al arrancar | Modo Bluetooth |

## Protocolo digital base PS1

| Byte | Valor | Descripcion |
|---:|---|---|
| 0 | 0xFF | Idle |
| 1 | 0x41 | Tipo: Digital Controller |
| 2 | 0x5A | Byte fijo |
| 3 | Botones 1 | Select / Start / D-Pad, 0 = presionado |
| 4 | Botones 2 | L2 / R2 / L1 / R1 / Triangulo / Circulo / Cruz / Cuadrado, 0 = presionado |

## Nota sobre PS2

PS1 y PS2 comparten conector y una base de comunicacion similar, pero el soporte PS2 / DualShock completo no forma parte del firmware PS1 publico.

Estado:

- Protocolo PS2 / DualShock: listo en build Hybrid AUTO.
- Firmware hibrido PS1/PS2/BLE: listo en build Hybrid AUTO.
- Distribucion: build de apoyo / donativos.
- Codigo fuente completo: no publicado en este repositorio publico.

Este repositorio mantiene publica la documentacion de la placa de repuesto ACT Labs REX y el firmware PS1 disponible.

## Plan de pruebas publico PS1

1. Verificar alimentacion y GND comun con consola.
2. Capturar ATT, CLK, CMD, DATA y ACK con analizador logico.
3. Confirmar respuesta base `0x41 0x5A`.
4. Validar que DATA quede estable antes del flanco esperado de CLK.
5. Ajustar pulso ACK hasta que la consola reconozca el control.
6. Probar botones uno por uno.
7. Activar AutoFire y confirmar alternancia de 50 ms ON / 50 ms OFF.

## Riesgos

- Timing estricto de ACK.
- Direccion de DATA y niveles electricos.
- Ruido o pull-up insuficiente en lineas de protocolo.
- El soporte PS2 completo queda fuera del firmware PS1 publico y se maneja como build Hybrid AUTO de apoyo.
