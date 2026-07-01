# Core Architecture

## Overview

The core module contains the foundational architecture of Smart Aquarium Guardian. It defines the reusable abstractions and patterns used throughout the firmware, including lifecycle management, communication contracts, and module coordination.

## Firmware Architecture Layers

The firmware is organized into a layered architecture to keep the system modular and maintainable.

![Firmware architecture diagram](docs/diagrams/firmware_architecture.png)

### 1. Core layer
Provides shared infrastructure for the entire system:
- base module lifecycle
- singleton patterns
- common interfaces and abstractions

### 2. Managers
Coordinate high-level behavior and orchestrate other subsystems:
- network management
- feeding control
- water monitoring
- UI coordination

### 3. Services
Implement domain-specific functionality:
- storage
- power handling
- real-time clock integration
- configuration and persistence logic

### 4. Drivers
Wrap hardware access in reusable abstractions:
- temperature sensors
- TDS sensing
- display control
- servo control
- I2C and GPIO utilities

### 5. Connectivity
Handles communication with the outside world:
- Wi-Fi setup and reconnection
- MQTT communication
- access-point configuration flow

### 6. UI
Responsible for local interaction:
- touchscreen input handling
- LVGL rendering
- status and control screens

## Design Principles

The architecture favors:
- separation of concerns
- clear module boundaries
- dependency inversion where appropriate
- centralized coordination through proxy or facade patterns

## Key Components

- GuardianProxy: central entry point for system operations
- GuardianPublicInterfaces: public contract exposed to upper layers
- Base module abstractions: reusable building blocks for managers, drivers, and services

## Relationship to the Rest of the Project

The core layer provides the foundation for managers, services, and drivers. The rest of the firmware depends on these abstractions rather than directly coupling to concrete implementations.

