# Firmware

## Modos

- **BLE HID**: funcional.
- **PS1**: en depuración de `ACK` / `DATA`.

## Pines V2

```cpp
static constexpr uint8_t PIN_PS1_DATA = 19;
static constexpr uint8_t PIN_PS1_CMD  = 23;
static constexpr uint8_t PIN_PS1_ATT  = 5;
static constexpr uint8_t PIN_PS1_CLK  = 18;
static constexpr uint8_t PIN_PS1_ACK  = 4;

static constexpr uint8_t PIN_START   = 21;
static constexpr uint8_t PIN_SELECT  = 22;
static constexpr uint8_t PIN_AF_MODE = 15;
```

## Estado actual

| Subsistema | Estado |
|---|---|
| Lectura GPIO | Pendiente de validar contra PCB V2 |
| BLE HID | Operativo |
| PS1 DATA | En depuración |
| PS1 ACK | En depuración |
| AutoFire | Pendiente de validar con placa física |

## Notas para depuración PS1

1. Usar analizador lógico con canales `ATT`, `CLK`, `CMD`, `DATA` y `ACK`.
2. Confirmar que `DATA` quede estable antes del flanco esperado de `CLK`.
3. Confirmar pulso `ACK` en LOW y retorno a HIGH.
4. Validar pull-up de 4.7 kΩ en las líneas indicadas por BOM V2.
5. Probar primero respuesta digital básica `0x41 0x5A` antes de mapear botones completos.

## Secuencia sugerida de implementación

1. Definir constantes de pines V2.
2. Hacer sketch de prueba solo para lectura de botones y salida serial.
3. Validar START/SELECT y `AF_MODE`.
4. Validar BLE HID.
5. Implementar tabla de estado de botones activa en bajo.
6. Implementar PS1 con interrupciones o lectura por flanco de `CLK`.
7. Medir y ajustar `ACK`.
