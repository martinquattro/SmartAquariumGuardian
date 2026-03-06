# Hardware Design - Smart Aquarium Guardian

This directory serves as the central repository for all electronic design files (EDA) related to the **Smart Aquarium Guardian** project. The hardware architecture is modular, consisting of the Main Controller Board and the Power Supply Board.

## 📂 Modules

### 1. Main Controller Board (Current Active Project)
This is the core of the system, responsible for:
* **Processing:** ESP32 Microcontroller logic.
* **Sensing:** Interfaces for TDS (Total Dissolved Solids) and Temperature sensors.
* **Actuation:** Control signals for external peripherals.

### 2. Power Supply Board
Provides mains-independent operation with USB charging and battery backup. Key features:
* **USB Type-C Input:** Power-only 6P receptacle for 5V charging.
* **Li-ion/LiPo Charging:** TP4056 1A linear charger for single-cell batteries (4.2V).
* **Battery Backup:** Automatic switch to battery when USB power is lost (power path switching via P-Channel MOSFET).
* **Boost Output:** MT3608 step-up DC-DC converter to supply stable 5V from battery to the main controller.
* **Status Indicators:** Red (charging) and green (charged) LEDs.
* **Output:** Connector for main board power supply.


## 🛠️ Directory Structure & Portability

The project is designed using **KiCad EDA**. It is structured to be **fully self-contained**, meaning no external global libraries are required to view or edit the files.

```text
/kicad
├── .gitignore                   # gitignore file for this folder
├── smart_aquarium_guardian/     # Main Controller Board
│   ├── lib/                     # Project-specific Local Libraries
│   │   ├── *.kicad_sym          # Custom Schematic Symbols
│   │   └── Guardian.pretty/     # Custom PCB Footprints
│   ├── datasheets/              # Technical documentation for critical components
│   ├── fp-lib-table             # Footprint Library Table (Maps local footprints)
│   ├── sym-lib-table            # Symbol Library Table (Maps local symbols)
│   ├── smart_aquarium_guardian.kicad_pro
│   ├── smart_aquarium_guardian.kicad_sch
│   └── smart_aquarium_guardian.kicad_pcb
│
└── power_supply/                # Power Supply Board
    ├── lib/                     # Power Supply Local Libraries
    │   ├── Power_Supply.kicad_sym
    │   └── PowerSupply.pretty/
    ├── production/              # Manufacturing outputs (Gerbers, BOM, drill files)
    ├── fp-lib-table
    ├── sym-lib-table
    ├── power_supply.kicad_pro
    ├── power_supply.kicad_sch
    └── power_supply.kicad_pcb
```

## 🚀 Usage & Workflow

To ensure the integrity of the design and library links, please follow these steps:

### Prerequisites
* **Software:** KiCad EDA
* **Version:** **9.0** or later.
  * *Note: Files saved in KiCad 9.0 are not backward compatible with older versions (6.0/7.0/8.0).*

### How to Open
1. **Clone the Repository:**
   Ensure you have the full directory structure, as the project relies on relative paths.
2. **Launch KiCad:**
   Open the desired project file (`.kicad_pro`):
   * Main Controller: `kicad/smart_aquarium_guardian/smart_aquarium_guardian.kicad_pro`
   * Power Supply: `kicad/power_supply/power_supply.kicad_pro`
3. **Access Design Files:**
   * **Schematic:** Open the Schematic Editor (`.kicad_sch`) to view the logical connections.
   * **PCB Layout:** Open the PCB Editor (`.kicad_pcb`) to view the physical routing and placement.
