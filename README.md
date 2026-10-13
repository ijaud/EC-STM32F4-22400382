---
description: EC_HAL API
---


# Embedded Controller - STM32f411 HAL API

Documentation for HAL functions

Written by:   Jimyeong Song

Course:  Embedded Controller

Program: C/C++

IDE/Compiler: Keil uVision 5

OS: WIn10

MCU:  STM32F411RE (Nucleo-64)



---

[TOC]

  * [GPIO Digital In/Out](#gpio-digital-inout)
    + [Header File](#header-file)
    + [GPIO_init\(\)](#gpio_init)
    + [GPIO_mode\(\)](#gpio_mode)
    + [GPIO_write\(\)](#gpio_write)
    + [GPIO_read\(\)](#gpio_read)
    + [GPIO_ospeed\(\)](#gpio_ospeed)
    + [GPIO_otype\(\)](#gpio_otype)
    + [GPIO_pupd\(\)](#gpio_pupd)

---

## GPIO Digital In/Out

### Header File

`#include "ecGPIO2.h"`

```c
#include "stm32f411xe.h"
#include "ecRCC2.h"
#include "ecPinNames.h"

#ifndef __ECGPIO2_H
#define __ECGPIO2_H

// MODER
#define INPUT  		0x00
#define OUTPUT 		0x01
#define AF     		0x02
#define ANALOG 		0x03

// IDR & ODR
#define HIGH 		1
#define LOW  		0

// OSPEEDR
#define LOW_SPEED		0x00
#define MEDIUM_SPEED	0x01
#define FAST_SPEED		0x10

// OTYPER
#define PUSH_PULL 		0	// Push-pull
#define OPEN_DRAIN 		1 	// Open-Drain

// PUPDR
#define NO_PUPD			0x00 	// No pull-up, pull-down
#define PULL_UP			0x01 	// Pull-up
#define PULL_DOWN 		0x02 	// Pull-down

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

void GPIO_init(PinName_t pinName, uint32_t mode);
void GPIO_mode(PinName_t pinName, uint32_t mode);
void GPIO_ospeed(PinName_t pinName, uint32_t speed);
void GPIO_otype(PinName_t pinName, uint32_t type);
void GPIO_pupd(PinName_t pinName, uint32_t pupd);
void GPIO_write(PinName_t pinName, uint32_t Output);
uint32_t GPIO_read(PinName_t pinName);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

> **Note:** This is the v2 pin API. Instead of a separate `GPIO_TypeDef* Port` + `int pin` pair, every function takes a single `PinName_t` value (e.g. `PA_5`, `PC_13`) that encodes both the port and pin number. The mapping is resolved internally by `ecPinmap()` (declared in `ecPinNames.h`).

### GPIO_init()

Initializes a GPIO pin with its default settings and automatically enables that pin's port clock (`RCC_GPIOx_enable()`) before configuring the mode.

```c
void GPIO_init(PinName_t pinName, uint32_t mode);
```

**Parameters**

* **pinName**: pin to configure, e.g. `PA_5`, `PC_13`
* **mode**: `INPUT` (0), `OUTPUT` (1), `AF` (2), `ANALOG` (3)

**Example code**

```c
GPIO_init(PA_5, OUTPUT);
GPIO_init(PC_13, INPUT);
```

### GPIO_mode()

Configures a GPIO pin's mode (In/Out/AF/Analog) without touching its port clock. Called internally by `GPIO_init()`.

```c
void GPIO_mode(PinName_t pinName, uint32_t mode);
```

**Parameters**

* **pinName**: pin to configure
* **mode**: `INPUT` (0), `OUTPUT` (1), `AF` (2), `ANALOG` (3)

**Example code**

```c
GPIO_mode(PA_5, OUTPUT);
```

### GPIO_write()

Writes a digital level (HIGH/LOW) to a GPIO pin's output register.

```c
void GPIO_write(PinName_t pinName, uint32_t Output);
```

**Parameters**

* **pinName**: pin to write to
* **Output**: `LOW` (0) or `HIGH` (1)

**Example code**

```c
GPIO_write(PA_5, HIGH);
```

### GPIO_read()

Reads the current digital level of a GPIO pin's input register.

```c
uint32_t GPIO_read(PinName_t pinName);
```

**Parameters**

* **pinName**: pin to read

**Returns**: `0` (LOW) or `1` (HIGH)

**Example code**

```c
uint32_t val = GPIO_read(PC_13);
```

### GPIO_ospeed()

Configures the output slew-rate speed of a GPIO pin.

```c
void GPIO_ospeed(PinName_t pinName, uint32_t speed);
```

**Parameters**

* **pinName**: pin to configure
* **speed**: `LOW_SPEED` (0x00), `MEDIUM_SPEED` (0x01), `FAST_SPEED` (0x10)

**Example code**

```c
GPIO_ospeed(PA_5, FAST_SPEED);
```

### GPIO_otype()

Configures a GPIO pin's output type: push-pull or open-drain.

```c
void GPIO_otype(PinName_t pinName, uint32_t type);
```

**Parameters**

* **pinName**: pin to configure
* **type**: `PUSH_PULL` (0) or `OPEN_DRAIN` (1)

**Example code**

```c
GPIO_otype(PA_5, PUSH_PULL);
```

### GPIO_pupd()

Configures a GPIO pin's internal pull-up/pull-down resistor.

```c
void GPIO_pupd(PinName_t pinName, uint32_t pupd);
```

**Parameters**

* **pinName**: pin to configure
* **pupd**: `NO_PUPD` (0x00), `PULL_UP` (0x01), `PULL_DOWN` (0x02)

**Example code**

```c
GPIO_pupd(PC_13, PULL_UP);
```



------



## Class or Header name

### Function Name

```text

```

**Parameters**

* p1
* p2

**Example code**

```text

```
