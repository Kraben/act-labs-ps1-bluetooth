# ACT Labs PS1 Bluetooth / AutoFire

Documentación técnica consolidada para la conversión de un tablero ACT-LABS / PS1 a control PS1-Bluetooth usando ESP32, con soporte para modo PS1, modo Bluetooth HID y placa secundaria de AutoFire.

> Estado: documentación inicial basada en esquemáticos KiCad, PCB exportado y mapeo consolidado en Excel.

## Contenido del repositorio

```text
.
├── README.md
├── docs/
│   ├── arquitectura.md
│   ├── mapeo-gpio.md
│   ├── conectores.md
│   ├── autofire.md
│   ├── firmware.md
│   └── bom.md
├── hardware/
│   ├── README.md
│   ├── pdf/
│   │   ├── ACT_Labs_REX.pdf
│   │   ├── ArcLabsPCB.pdf
│   │   ├── AutoFire.pdf
│   │   └── AutoFirePCB.pdf
│   └── images/
│       ├── Led-Switch.png
│       ├── Partcial_SCHM.png
│       └── SW_part.png
├── data/
│   ├── ACT_Labs_Mapeo_Consolidado.xlsx
│   ├── gpio_mapping.csv
│   ├── placa_2_autofire.csv
│   ├── jp1_conector_puente.csv
│   └── firmware_resumen.md
└── firmware/
    └── ACT_Labs_Controller/
        └── ACT_Labs_Controller.ino
```

## Resumen del proyecto

El sistema usa un ESP32 como controlador principal. Dependiendo del estado de `PS1_ATT` al arranque, el firmware puede operar como emulador de control digital PS1 o como gamepad Bluetooth HID. La placa secundaria AutoFire agrega interruptores SPDT para activar turbo por botón y un interruptor de encendido desde batería.

## Referencias rápidas

- Esquemático principal: [`hardware/pdf/ACT_Labs_REX.pdf`](hardware/pdf/ACT_Labs_REX.pdf)
- PCB principal: [`hardware/pdf/ArcLabsPCB.pdf`](hardware/pdf/ArcLabsPCB.pdf)
- Esquemático AutoFire: [`hardware/pdf/AutoFire.pdf`](hardware/pdf/AutoFire.pdf)
- PCB AutoFire: [`hardware/pdf/AutoFirePCB.pdf`](hardware/pdf/AutoFirePCB.pdf)
- Mapeo completo: [`data/ACT_Labs_Mapeo_Consolidado.xlsx`](data/ACT_Labs_Mapeo_Consolidado.xlsx)

## Pines principales

| Grupo | Señales |
|---|---|
| Botones frontales | Triángulo, Círculo, Cuadrado, Cruz |
| Botones laterales | L1, L2, R1, R2 |
| D-Pad | Arriba, Abajo, Izquierda, Derecha |
| PS1 SPI | DATA, CMD, ATT, CLK, ACK |
| AutoFire | AF_MODE, señales AF por botón |
| Alimentación | VCC_3V3, GND, BATT_FROM_TP, VIN |

## Modo de operación previsto

1. **Modo PS1**: si `PS1_ATT` está en LOW al arrancar, la consola está activa y se usa emulación SPI.
2. **Modo Bluetooth**: si `PS1_ATT` está en HIGH al arrancar, no hay consola conectada y se anuncia como HID Gamepad BLE.
3. **AutoFire**: si un GPIO permanece en LOW más de 150 ms, se interpreta como turbo activo; se sugiere alternancia de 50 ms ON / 50 ms OFF.

## Cómo continuar

1. Revisar esquemáticos y validar continuidad contra PCB físico.
2. Confirmar polaridad de botones: activo en LOW con pull-up interno o externo.
3. Implementar y probar firmware por etapas: lectura GPIO, PS1 SPI, HID BLE y turbo.
4. Agregar capturas/fotos de ensamblaje real en `hardware/images/`.
5. Documentar errores conocidos y revisiones en issues del repositorio.
