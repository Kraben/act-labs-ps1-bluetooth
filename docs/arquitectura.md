# Arquitectura del sistema

## Objetivo

Convertir un tablero ACT-LABS / PS1 en un control híbrido con dos modos:

- **PS1/PS2 cableado** mediante emulación de control digital PS1.
- **Bluetooth HID** mediante ESP32 cuando no se detecta consola.

## Bloques funcionales

### 1. ESP32

El ESP32 lee botones, D-Pad y switches de AutoFire, y genera la salida de datos hacia el conector PS1 o el reporte HID BLE.

### 2. Interfaz PS1

La interfaz PS1 usa líneas tipo SPI:

| Señal | Rol | Dirección lógica |
|---|---|---|
| PS1_DATA | Mando a consola | Salida |
| PS1_CMD | Consola a mando | Entrada |
| PS1_ATT | Chip select | Entrada |
| PS1_CLK | Reloj | Entrada |
| PS1_ACK | Acknowledge | Salida |

El protocolo usa lógica activa en bajo para botones: `0 = presionado`, `1 = suelto`.

### 3. Placa AutoFire

La placa secundaria contiene switches SPDT conectados a señales `AF_*`. Cada interruptor puede dejar el botón en modo directo o llevar la señal a GND para activar turbo.

### 4. Alimentación

- `VCC_3V3`: alimentación lógica a 3.3 V.
- `BATT_FROM_TP`: alimentación desde módulo TP4056 / batería.
- `D1 SS14`: diodo de protección/aislamiento en la ruta `PWR_TO_DIODE` / `OUT+`.
- `SW10`: encendido del modo Bluetooth desde batería.

## Flujo de arranque

1. Inicializar pines de entrada con pull-up cuando aplique.
2. Leer `PS1_ATT`.
3. Si `PS1_ATT` está LOW, entrar en modo PS1.
4. Si `PS1_ATT` está HIGH, entrar en modo Bluetooth HID.
5. Ejecutar lectura periódica de botones y lógica de AutoFire.
