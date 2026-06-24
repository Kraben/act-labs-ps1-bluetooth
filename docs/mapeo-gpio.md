# Mapeo GPIO V2

Mapa funcional actualizado para el firmware ESP32.

## Interfaz PS1

| Señal | GPIO ESP32 | Dirección lógica | Nota |
|---|---:|---|---|
| DATA | 19 | Salida | Mando -> consola |
| CMD | 23 | Entrada | Consola -> mando |
| ATT | 5 | Entrada | Selección / atención de consola |
| CLK | 18 | Entrada | Reloj de consola |
| ACK | 4 | Salida | Pulso de acknowledge |

## Controles principales

| Señal | GPIO ESP32 | Nota |
|---|---:|---|
| START | 21 | Botón START |
| SELECT | 22 | Botón SELECT |
| AF_MODE | 15 | Modo turbo global |

## Señales AutoFire / botones

Las señales `AF_*` conectan la placa principal con la placa AutoFire y los switches SPDT. La lógica esperada es activa en bajo: `LOW = presionado / activo`, `HIGH = suelto`.

| Grupo | Señales |
|---|---|
| Botones frontales | `AF_TRIANGULO`, `AF_CIRCULO`, `AF_CUADRADO`, `AF_CRUZ` |
| Botones laterales | `AF_L1`, `AF_L2`, `AF_R1`, `AF_R2` |
| Modo turbo | `AF_MODE` |
| Encendido batería | `BATT_FROM_TP` por SW10 |

## Pull-ups y notas eléctricas

- `DATA` y `ACK` se documentan con pull-up de **4.7 kΩ** según BOM V2 (`R6`, `R7`).
- Entradas con lógica de botón deben configurarse como `INPUT_PULLUP` cuando el GPIO lo permita.
- Validar con multímetro/analizador lógico antes de soldar definitivo.
- Para depuración PS1, registrar `ATT`, `CLK`, `CMD`, `DATA` y `ACK` simultáneamente.

## Constantes sugeridas para firmware

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
