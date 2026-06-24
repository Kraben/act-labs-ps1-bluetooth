# ACT Labs PS1 Bluetooth / AutoFire

Documentación técnica consolidada para la conversión de un tablero ACT-LABS / PS1 a control híbrido PS1-Bluetooth usando ESP32, con soporte para modo PS1, modo Bluetooth HID y placa secundaria AutoFire.

> Estado actual: Hardware V2 / PCB V2.2, BLE operativo y protocolo PS1 en depuración de ACK/DATA.

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
│   ├── bom.md
│   ├── fabricacion.md
│   └── revision-v2.md
├── hardware/
│   ├── README.md
│   ├── fabrication/
│   │   ├── ACT_Labs_REX_BOM_summary.csv
│   │   ├── ACT_Labs_REX_POS_summary.csv
│   │   ├── autofire_bom_summary.txt
│   │   └── autofire_pos_summary.txt
│   ├── kicad/
│   │   └── SOURCES.md
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

El sistema usa un ESP32 DevKit V1 como controlador principal. El mismo hardware debe poder funcionar en dos escenarios:

1. **Modo PS1/PS2 cableado**: el ESP32 emula un control digital PS1 usando DATA, CMD, ATT, CLK y ACK.
2. **Modo Bluetooth HID**: el ESP32 funciona como gamepad BLE cuando se usa con batería.
3. **AutoFire**: una placa secundaria con switches SPDT permite activar turbo por botón y controlar el encendido desde batería.

## Estado técnico V2

| Área | Estado |
|---|---|
| Hardware | V2 / PCB V2.2 |
| KiCad | Archivos generados en KiCad 10 |
| BLE | Operativo |
| PS1 | En depuración de ACK/DATA |
| Alimentación | TP4056 externo, batería PS Vita 3.7 V, LD1117-3.3 y diodo Schottky |

## Referencias rápidas

- Esquemático principal PDF: [`hardware/pdf/ACT_Labs_REX.pdf`](hardware/pdf/ACT_Labs_REX.pdf)
- PCB principal PDF: [`hardware/pdf/ArcLabsPCB.pdf`](hardware/pdf/ArcLabsPCB.pdf)
- Esquemático AutoFire PDF: [`hardware/pdf/AutoFire.pdf`](hardware/pdf/AutoFire.pdf)
- PCB AutoFire PDF: [`hardware/pdf/AutoFirePCB.pdf`](hardware/pdf/AutoFirePCB.pdf)
- BOM/POS de fabricación: [`hardware/fabrication/`](hardware/fabrication/)
- Inventario de fuentes KiCad recibidas: [`hardware/kicad/SOURCES.md`](hardware/kicad/SOURCES.md)
- Mapeo completo: [`data/ACT_Labs_Mapeo_Consolidado.xlsx`](data/ACT_Labs_Mapeo_Consolidado.xlsx)

## Pines principales V2

| Señal | GPIO |
|---|---:|
| DATA | 19 |
| CMD | 23 |
| ATT | 5 |
| CLK | 18 |
| ACK | 4 |
| START | 2 |
| SELECT | 16 |
| AF_MODE | 15 |

## Próximos pasos

1. Validar continuidad entre PCB principal, placa AutoFire y conectores JP.
2. Revisar la ruta de alimentación `BATT_FROM_TP`, TP4056, LD1117-3.3 y D1.
3. Depurar ACK/DATA del protocolo PS1 con analizador lógico.
4. Confirmar pull-ups reales contra la PCB antes de fabricar.
5. Mantener BOM/POS exportados desde KiCad antes de fabricar.
