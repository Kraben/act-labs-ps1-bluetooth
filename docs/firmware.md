# Firmware

## Version publica actual

| Campo | Valor |
|---|---|
| Version | PS1 Digital v1.1 |
| Estado | OK |
| Archivo | [`ActLabs_PS1_Digital_v1.1_OK.bin`](../firmware/releases/PS1_Digital/v1.1/ActLabs_PS1_Digital_v1.1_OK.bin) |
| Ruta | [`firmware/releases/PS1_Digital/v1.1/`](../firmware/releases/PS1_Digital/v1.1/) |
| Target | ACT Labs REX PS1 Replacement PCB |
| Hardware | V2 / KiCad actualizado |
| SHA256 | `0a8994050381326bf345bf8123c105abefadabf30187247be9129a8c7f34b15c` |
| MD5 | `f61375d0dea1b9e42a6903105f5fba79` |

## Modos

- PS1: firmware publico actualizado a PS1 Digital v1.1 OK para el alcance ACT Labs REX / PS1.
- BLE HID: funcional.
- PS2 / DualShock: listo en firmware Hybrid AUTO para build de apoyo/donativos.
- Hibrido PS1/PS2/BLE: listo en firmware Hybrid AUTO para build de apoyo/donativos.

## Politica de publicacion

Este repositorio publico conserva la documentacion, hardware, Gerbers y firmware PS1 disponible para la placa de repuesto ACT Labs REX.

El firmware Hybrid AUTO se maneja como **build de apoyo/donativos** para sostener el desarrollo. Esta build agrega PS1, PS2 / DualShock, Bluetooth BLE HID y deteccion automatica de modo.

No se publica aqui el codigo fuente completo del firmware Hybrid AUTO. La documentacion publica describe el alcance, compatibilidad esperada, checklist de pruebas y recomendaciones de flasheo.

## Firmware Hybrid AUTO de apoyo

| Campo | Valor |
|---|---|
| Nombre | Hybrid AUTO |
| Plataforma | ESP32 DevKit V1 |
| Modos | PS1 / PS2 / BLE |
| Deteccion | Automatica |
| Distribucion | Build de apoyo / donativos |
| Fuente completa | No publicada en este repositorio publico |
| Documentacion | [`supporter-build.md`](supporter-build.md) |

## Deteccion de modo publico

| Condicion | Modo | Descripcion |
|---|---|---|
| Consola PS1 activa | Modo PS1 | Emulacion digital PS1 |
| Consola PS2 activa | Modo PS2 | Emulacion PS2 / DualShock en build Hybrid AUTO |
| Sin actividad de consola | Modo Bluetooth | HID Gamepad BLE |
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

El protocolo PS2 / DualShock ya fue desarrollado para la build Hybrid AUTO de apoyo/donativos.

Estado publico:

- No se publica el codigo completo en este repositorio.
- No se documentan aqui los detalles completos de handshake ni modo analogico.
- Se mantiene como referencia de roadmap y compatibilidad de la build de apoyo.

## Estado actual

| Subsistema | Estado |
|---|---|
| Firmware PS1 | PS1 Digital v1.1 OK publicado como binario |
| BLE HID | Operativo |
| PS2 / DualShock | Listo en build Hybrid AUTO de apoyo |
| Hibrido PS1/PS2/BLE | Listo en build Hybrid AUTO de apoyo |
| AutoFire | Pendiente de validar con placa fisica |

## Notas para depuracion PS1

1. Usar analizador logico con canales ATT, CLK, CMD, DATA y ACK.
2. Confirmar que DATA quede estable antes del flanco esperado de CLK.
3. Confirmar pulso ACK en LOW y retorno a HIGH.
4. Probar primero respuesta digital basica 0x41 0x5A antes de mapear botones completos.
5. Validar START en GPIO2 y SELECT en GPIO16.

## Notas de release

- Descargar el binario publico PS1 desde `firmware/releases/PS1_Digital/v1.1/`.
- Confirmar checksum antes de flashear.
- Probar primero en hardware ACT Labs REX V2 / KiCad actualizado.
- Para la build Hybrid AUTO de apoyo, publicar binario, checksums y guia de flasheo por separado.
