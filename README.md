
# Smart Aquarium Guardian

ESP32-based aquarium monitoring and automation system with real-time telemetry, scheduled feeding, and an intuitive graphical user interface.

## Overview

  

Smart Aquarium Guardian is a comprehensive IoT solution for automated aquarium management. The system provides real-time monitoring of water conditions, automated feeding capabilities, and remote control via MQTT, all managed through an intuitive touchscreen interface.

  

## Features

  

### Core Functionality

  

- **Real-time Water Monitoring**

	- Temperature sensing via DS18B20 OneWire sensors

	- TDS (Total Dissolved Solids) water quality measurement

	- Configurable alert thresholds with immediate notifications

	- Data logging and historical tracking

  

- **Automated Feeding System**

	- Servo-controlled food dispenser with precise dosage control

	- Up to 10 configurable daily feeding schedules

	- Manual feeding via commands

  

- **Network Integration**

	- MQTT client for telemetry publishing and remote command reception

	- WiFi connectivity management with automatic reconnection

	- Real-time data synchronization

  

- **Graphical User Interface**

	- LVGL 9.1.0-based touchscreen UI (ILI9341 SPI LCD, 320x240)

	- Real-time sensor value display with alert state indicators

	- Feeding status information

	- Time and connection status

  

- **System Management**

	- Real-time clock synchronization (SNTP)

	- Timezone-aware scheduling

	- Non-volatile configuration storage (EEPROM)

	- Auto switch battery back-up in case of power outage

  
  

## Building and Flashing

  

### Prerequisites

  

- PlatformIO (https://platformio.org/)

- ESP-IDF 5.1+ installed and configured

- Python 3.8+
  

## API Documentation with Doxygen

  

This project uses **Doxygen** to generate professional HTML API documentation from source code comments.

  

#### Quick Start

  
- Generate HTML doxygen doccumentation based on Doxyfile configuration
```powershell
>doxygen Doxyfile
```
- Open documentation

Generated files are seved inside ``/docs/doxygen/`` folder. HTML index can accesed through
```
\docs\doxygen\html\index.html
```

#### Requirements

- Doxygen (https://www.doxygen.nl/download.html)

- Graphviz (for diagrams: https://graphviz.org/download/)

  

#### Build Integration

  
Pre-build **Python** task that automatically runs Doxygen generation on every build, to keep documentation up-to-date locally. Script path
```
\scripts\run_doxygen.py
```

  

## License

  

This project is licensed under the **MIT License** - see [LICENSE](LICENSE) file for details.

  
---
**Project:** Smart Aquarium Guardian

**Author:** Quattrone Martin

**Created:** August 2025

**Status:** Stable Release

**IDF Version Requirement:** 5.1+

**C++ Standard:** C++17