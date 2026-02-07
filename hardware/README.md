# Hardware Design - Smart Aquarium Guardian

This directory serves as the central repository for all electronic design files (EDA) related to the **Smart Aquarium Guardian** project. The hardware architecture is modular, consisting of the Main Controller Board.

## 📂 Modules

### 1. Main Controller Board (Current Active Project)
This is the core of the system, responsible for:
* **Processing:** ESP32 Microcontroller logic.
* **Sensing:** Interfaces for TDS (Total Dissolved Solids) and Temperature sensors.
* **Actuation:** Control signals for external peripherals.


## 🛠️ Directory Structure & Portability

The project is designed using **KiCad EDA**. It is structured to be **fully self-contained**, meaning no external global libraries are required to view or edit the files.

```text
/hardware
├── README.md                    # This documentation file
├── .gitignore                   # gitignore file for this folder
└── smart_aquarium_guardian/     # Main Project Folder
    ├── lib/                     # Project-specific Local Libraries
    │   ├── *.kicad_sym          # Custom Schematic Symbols
    │   └── *.pretty             # Custom PCB Footprints
    ├── datasheets/              # Technical documentation for critical components
    ├── fp-lib-table             # Footprint Library Table (Maps local footprints)
    ├── sym-lib-table            # Symbol Library Table (Maps local symbols)
    ├── smart_aquarium...pro     # KiCad Project Manager
    ├── smart_aquarium...sch     # Main Schematic
    └── smart_aquarium...pcb     # PCB Layout
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
   Open the main project file `.kicad_pro`.
3. **Access Design Files:**
   * **Schematic:** Open the Schematic Editor (`.kicad_sch`) to view the logical connections.
   * **PCB Layout:** Open the PCB Editor (`.kicad_pcb`) to view the physical routing and placement.

*Note: You do not need to install any external global libraries. All symbols and footprints
```