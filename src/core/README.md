
 
# Core Architecture
## Overview

  

  

The `core` module contains the foundational architecture for the SmartAquariumGuardian system. It defines the base classes and patterns used throughout the application.

  
  

## Structure

### `guardian_public_interfaces`

  Defines the **external communication contract** of the system.

-   **Pure Abstract Interface**: Acts as a strict contract declaring all system capabilities available to the outside world.
    
-   **Decoupling**: Allows modules to interact with the system without knowledge of internal classes like `FoodFeeder` or `WaterMonitor`.


### `guardian_proxy`
Implements the public interface and acts as the **gateway to the core** .

-   **Facade / Proxy Pattern**: Serves as the single entry point for external commands, simplifying system complexity.
    
-   **Command Orchestration**: Receives calls defined in `GuardianPublicInterfaces` and delegates them to the corresponding **Singleton Manager**.
        
-   **Isolation**: Protects Managers from unnecessary direct access by upper layers, maintaining a clean and organized architecture.



 

### `base/`

  

Contains abstract base classes and patterns for all modules:

  

  

- **`module.h`** - Base class for all modules (Managers, Drivers, Services)

  

	- Provides `Init()` and `Update()` lifecycle methods

  

	- Requires `GetModuleName()` implementation

  

  

- **`singleton.h`** - Singleton CRTP template

  

	- Provides type-safe `GetInstance()` method for each derived class

  

	- Thread-safe lazy initialization (C++11)

  

	- One instance per class guaranteed

  

  

- **`manager.h`** - Base for coordinators

  

	- Orchestrates business logic

  

	- Inherits from `Singleton<T>` and `Module`

  

  

- **`driver.h`** - Base for hardware interfaces

  

	- Direct hardware communication

  

	- Inherits from `Singleton<T>` and `Module`

