# Firmware

## Modos

- BLE HID: funcional.
- PS1: en depuracion de ACK / DATA.

## Deteccion de modo

| Condicion | Modo | Descripcion |
|---|---|---|
| PS1_ATT = LOW al arrancar | Modo PS1 | Consola PS1/PS2 activa - emulacion SPI |
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

## Estado actual

| Subsistema | Estado |
|---|---|
| Lectura GPIO | Pendiente de validar contra PCB V2 |
| BLE HID | Operativo |
| PS1 DATA | En depuracion |
| PS1 ACK | En depuracion |
| AutoFire | Pendiente de validar con placa fisica |

## Notas para depuracion PS1

1. Usar analizador logico con canales ATT, CLK, CMD, DATA y ACK.
2. Confirmar que DATA quede estable antes del flanco esperado de CLK.
3. Confirmar pulso ACK en LOW y retorno a HIGH.
4. Probar primero respuesta digital basica 0x41 0x5A antes de mapear botones completos.
5. Validar START en GPIO2 y SELECT en GPIO16; estos valores reemplazan GPIO21/GPIO22 de documentacion previa.
