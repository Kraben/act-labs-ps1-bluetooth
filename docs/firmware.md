# Firmware

## Modos

- PS1: firmware publico actualizado para el alcance ACT Labs REX / PS1.
- BLE HID: funcional.
- PS2 / DualShock: protocolo listo a nivel de desarrollo, pero reservado para version privada/paywall.
- Hibrido PS1/PS2/BLE: listo a nivel de desarrollo, pero no publicado en este repositorio publico.

## Politica de publicacion

Este repositorio publico conserva la documentacion y el firmware PS1 disponible para la placa de repuesto ACT Labs REX.

El protocolo PS2 y el firmware hibrido PS1/PS2/BLE se manejaran como trabajo privado/paywall. No se publicara aqui el codigo fuente completo de esas funciones.

## Deteccion de modo

| Condicion | Modo | Descripcion |
|---|---|---|
| PS1_ATT = LOW al arrancar | Modo PS1 | Consola PS1 activa - emulacion SPI |
| PS1_ATT = HIGH al arrancar | Modo Bluetooth | Sin consola - HID Gamepad BLE |
| SW10 Placa_2 = OFF | Apagado | Sin alimentacion desde bateria |

## Pines Rev 1.4 / V2

```cpp
static constexpr uint8_t PIN_PS1_DATA = 19;
static constexpr uint8_t PIN_PS1_CMD  = 23;
static constexpr uint8_t PIN_PS1_ATT  = 5;
static constexpr uint8_t PIN_PS1_CLK  = 18;
static constexpr uint8_t PIN_PS1_ACK  = 4;

static constexpr uint8_t PIN_START   = 2;
static constexpr uint8_t PIN_SELECT  = 16;
static constexpr uint8_t PIN_AF_MODE = 15;
```

## Logica Turbo / AutoFire

| Condicion GPIO | Duracion | Comportamiento |
|---|---:|---|
| GPIO HIGH | - | Boton suelto - sin accion |
| GPIO LOW | < 150 ms | Pulsacion normal del usuario |
| GPIO LOW continuo | > 150 ms | SW ON jalando a GND = TURBO activo |
| TURBO activo | 50 ms ON / 50 ms OFF | 10 pulsaciones por segundo |

## Protocolo PS1 SPI

| Byte | Valor | Descripcion |
|---:|---|---|
| 0 | 0xFF | Idle |
| 1 | 0x41 | Tipo: Digital Controller |
| 2 | 0x5A | Fijo siempre |
| 3 | Botones 1 | Select/Start/D-Pad - 0=presionado |
| 4 | Botones 2 | L2/R2/L1/R1/Triangulo/Circulo/Cruz/Cuadrado - 0=presionado |

## Protocolo PS2

El protocolo PS2 / DualShock ya fue desarrollado y queda marcado como listo para distribucion privada/paywall.

Estado publico:

- No se publica el codigo completo en este repositorio.
- No se documentan aqui los detalles completos de handshake ni modo analogico.
- Se mantiene como referencia de roadmap privado.

## Estado actual

| Subsistema | Estado |
|---|---|
| Firmware PS1 | Actualizado manualmente en el repositorio |
| BLE HID | Operativo |
| PS2 / DualShock | Listo, reservado para paywall |
| Hibrido PS1/PS2/BLE | Listo, reservado para paywall |
| AutoFire | Pendiente de validar con placa fisica |

## Notas para depuracion PS1

1. Usar analizador logico con canales ATT, CLK, CMD, DATA y ACK.
2. Confirmar que DATA quede estable antes del flanco esperado de CLK.
3. Confirmar pulso ACK en LOW y retorno a HIGH.
4. Probar primero respuesta digital basica 0x41 0x5A antes de mapear botones completos.
5. Validar START en GPIO2 y SELECT en GPIO16; estos valores reemplazan GPIO21/GPIO22 de documentacion previa.
