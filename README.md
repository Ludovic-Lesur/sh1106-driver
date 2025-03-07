# Description

This repository contains the **SH1106** LCD screen driver.

# Dependencies

The driver relies on:

* An external `types.h` header file defining the **standard C types** of the targeted MCU.
* The **embedded utility functions** defined in the [embedded-utils](https://github.com/Ludovic-Lesur/embedded-utils) repository.

Here is the versions compatibility table:

| **sh1106-driver** | **embedded-utils** |
|:---:|:---:|
| [sw1.1](https://github.com/Ludovic-Lesur/sh1106-driver/releases/tag/sw1.1) | >= [sw7.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw7.0) |
| [sw1.0](https://github.com/Ludovic-Lesur/sh1106-driver/releases/tag/sw1.0) | [sw6.0](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw6.0) to [sw6.2](https://github.com/Ludovic-Lesur/embedded-utils/releases/tag/sw6.2) |

# Compilation flags

| **Flag name** | **Value** | **Description** |
|:---:|:---:|:---:|
| `SH1106_DRIVER_DISABLE_FLAGS_FILE` | `defined` / `undefined` | Disable the `sh1106_driver_flags.h` header file inclusion when compilation flags are given in the project settings or by command line. |
| `SH1106_DRIVER_DISABLE` | `defined` / `undefined` | Disable the SH1106 driver. |
| `SH1106_DRIVER_I2C_ERROR_BASE_LAST` | `<value>` | Last error base of the low level I2C driver. |
