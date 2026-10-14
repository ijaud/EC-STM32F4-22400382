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
  * [RCC (System / Peripheral Clock)](#rcc-system--peripheral-clock)
    + [Header File](#header-file-1)
    + [RCC_HSI_init\(\)](#rcc_hsi_init)
    + [RCC_PLL_init\(\)](#rcc_pll_init)
    + [RCC_GPIOA_enable\(\) / RCC_GPIOB_enable\(\) / RCC_GPIOC_enable\(\) / RCC_GPIOD_enable\(\)](#rcc_gpioa_enable--rcc_gpiob_enable--rcc_gpioc_enable--rcc_gpiod_enable)
    + [delay_ms_HSI\(\)](#delay_ms_hsi)
  * [SysTick (1 ms System Timer)](#systick-1-ms-system-timer)
    + [Header File](#header-file-2)
    + [SysTick_init\(\)](#systick_init)
    + [SysTick_Handler\(\)](#systick_handler)
    + [SysTick_counter\(\)](#systick_counter)
    + [delay_ms\(\)](#delay_ms)
    + [SysTick_reset\(\)](#systick_reset)
    + [SysTick_val\(\)](#systick_val)
  * [EXTI (External Interrupt)](#exti-external-interrupt)
    + [Header File](#header-file-3)
    + [EXTI_init\(\)](#exti_init)
    + [EXTI_enable\(\) / EXTI_disable\(\)](#exti_enable--exti_disable)
    + [is_pending_EXTI\(\)](#is_pending_exti)
    + [clear_pending_EXTI\(\)](#clear_pending_exti)
  * [Stepper Motor (FSM-based)](#stepper-motor-fsm-based)
    + [Header File](#header-file-4)
    + [stepper_init\(\)](#stepper_init)
    + [stepper_speed\(\)](#stepper_speed)
    + [stepper_step\(\)](#stepper_step)
    + [stepper_out\(\)](#stepper_out)
    + [stepper_stop\(\)](#stepper_stop)
    + [getStepsPerRev\(\)](#getstepsperrev)

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

---

## RCC (System / Peripheral Clock)

### Header File

`#include "ecRCC2.h"`

```c
#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecPinNames.h"

#ifndef __EC_RCC2_H
#define __EC_RCC2_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

extern volatile int EC_SYSCLK;		// current SYSCLK [Hz], set by RCC_HSI_init()/RCC_PLL_init()

void delay_ms_HSI(uint32_t ms);
void RCC_HSI_init(void);
void RCC_PLL_init(void);
void RCC_GPIOA_enable(void);
void RCC_GPIOB_enable(void);
void RCC_GPIOC_enable(void);
void RCC_GPIOD_enable(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

### RCC_HSI_init()

Enables the internal 16 MHz HSI oscillator and selects it as the system clock source. Updates `EC_SYSCLK` to `16000000`.

```c
void RCC_HSI_init(void);
```

**Parameters**

* (none)

**Example code**

```c
RCC_HSI_init();   // SYSCLK = 16 MHz
```

### RCC_PLL_init()

Configures the PLL to run the system clock at 84 MHz (from the 16 MHz HSI source) and selects PLL as the system clock source. Updates `EC_SYSCLK` to `84000000`. Must be called before `SysTick_init()`, since SysTick's 1 ms reload value depends on `EC_SYSCLK`.

```c
void RCC_PLL_init(void);
```

**Parameters**

* (none)

**Example code**

```c
RCC_PLL_init();   // SYSCLK = 84 MHz
```

### RCC_GPIOA_enable() / RCC_GPIOB_enable() / RCC_GPIOC_enable() / RCC_GPIOD_enable()

Enables the AHB1 peripheral clock for the corresponding GPIO port. Must be called before configuring or using any pin on that port — this is done automatically inside `GPIO_init()`, so it rarely needs to be called directly.

```c
void RCC_GPIOA_enable(void);
void RCC_GPIOB_enable(void);
void RCC_GPIOC_enable(void);
void RCC_GPIOD_enable(void);
```

**Parameters**

* (none)

**Example code**

```c
RCC_GPIOD_enable();   // enable clock for GPIOD before using a PD_x pin
```

### delay_ms_HSI()

Busy-wait (blocking) delay in milliseconds, computed directly from `EC_SYSCLK` with a software loop. Does not use SysTick, so it works even before `SysTick_init()` has been called, but is less accurate than `delay_ms()`.

```c
void delay_ms_HSI(uint32_t ms);
```

**Parameters**

* **ms**: delay duration in milliseconds

**Example code**

```c
delay_ms_HSI(500);   // ~500 ms blocking delay
```

---

## SysTick (1 ms System Timer)

### Header File

`#include "ecSysTick2.h"`

```c
#include "stm32f4xx.h"
#include "ecRCC2.h"
#include <stdint.h>

#ifndef __EC_SYSTICK2_H
#define __EC_SYSTICK2_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

extern volatile uint32_t msTicks;

void SysTick_init(void);
void SysTick_Handler(void);
void SysTick_counter(void);
void delay_ms(uint32_t msec);
void SysTick_reset(void);
uint32_t SysTick_val(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

### SysTick_init()

Configures the SysTick timer to generate an interrupt every 1 ms, based on the current `EC_SYSCLK`. Must be called **after** `RCC_HSI_init()` or `RCC_PLL_init()`, since the reload value depends on the system clock frequency.

```c
void SysTick_init(void);
```

**Parameters**

* (none)

**Example code**

```c
RCC_PLL_init();     // set SYSCLK first
SysTick_init();      // then start the 1 ms tick
```

### SysTick_Handler()

The SysTick interrupt handler. Called automatically by the hardware every 1 ms once `SysTick_init()` is active — it is not meant to be called directly from user code. Internally calls `SysTick_counter()`.

```c
void SysTick_Handler(void);
```

**Parameters**

* (none, ISR)

### SysTick_counter()

Increments the global millisecond counter `msTicks` by 1. Called internally by `SysTick_Handler()` on every tick.

```c
void SysTick_counter(void);
```

**Parameters**

* (none)

### delay_ms()

Blocking delay of `msec` milliseconds, implemented by polling `msTicks` (which `SysTick_Handler()` increments every 1 ms in the background).

```c
void delay_ms(uint32_t msec);
```

**Parameters**

* **msec**: delay duration in milliseconds

**Example code**

```c
delay_ms(1000);   // blocks for 1 second
```

### SysTick_reset()

Resets the SysTick hardware down-counter (`SysTick->VAL`) to 0. Does not affect `msTicks`.

```c
void SysTick_reset(void);
```

**Parameters**

* (none)

### SysTick_val()

Returns the current value of the SysTick hardware down-counter.

```c
uint32_t SysTick_val(void);
```

**Parameters**

* (none)

**Example code**

```c
uint32_t v = SysTick_val();
```

---

## EXTI (External Interrupt)

### Header File

`#include "ecEXTI2.h"`

```c
#include "stm32f411xe.h"
#include "ecPinNames.h"

#ifndef __EC_EXTI2_H
#define __EC_EXTI2_H

#define FALL 0
#define RISE 1
#define BOTH 2

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

void EXTI_init(PinName_t pinName, uint32_t trig_type, uint32_t priority);
void EXTI_enable(PinName_t pinName);
void EXTI_disable(PinName_t pinName);
uint32_t is_pending_EXTI(PinName_t pinName);
void clear_pending_EXTI(PinName_t pinName);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

### EXTI_init()

Configures a pin as an external interrupt source: connects the EXTI line to the pin's port, selects the trigger edge, unmasks (enables) the EXTI line, and enables + sets the priority of the corresponding NVIC interrupt. The EXTI line number is determined by the pin number (not the port) — e.g. `PA_2` and `PD_2` both use EXTI line 2 and share the same handler name.

```c
void EXTI_init(PinName_t pinName, uint32_t trig_type, uint32_t priority);
```

**Parameters**

* **pinName**: pin to use as the interrupt source (e.g. `PA_5`, `PC_13`)
* **trig_type**: `FALL` (0), `RISE` (1), `BOTH` (2)
* **priority**: NVIC priority level (0 = highest, 15 = lowest)

**Example code**

```c
EXTI_init(PC_13, FALL, 10);   // interrupt on falling edge of PC_13, priority 10
```

### EXTI_enable() / EXTI_disable()

Unmasks or masks the EXTI line for the given pin (`EXTI->IMR`), without touching its trigger-edge configuration. Useful for temporarily enabling/disabling an interrupt that was already configured with `EXTI_init()`.

```c
void EXTI_enable(PinName_t pinName);
void EXTI_disable(PinName_t pinName);
```

**Parameters**

* **pinName**: pin whose EXTI line should be enabled/disabled

**Example code**

```c
EXTI_disable(SW1_JK);   // temporarily ignore SW1 interrupts
EXTI_enable(SW1_JK);     // re-enable them
```

### is_pending_EXTI()

Reads the EXTI pending-request register (`EXTI->PR`) for the given pin's line and returns whether an edge event is currently latched. This is a one-shot latch, not a live level read — once set, it stays set until explicitly cleared with `clear_pending_EXTI()`.

```c
uint32_t is_pending_EXTI(PinName_t pinName);
```

**Parameters**

* **pinName**: pin whose EXTI line to check

**Returns**: `1` if the line's pending bit is set, `0` otherwise

**Example code**

```c
if (is_pending_EXTI(SW1_JK)) { ... }
```

### clear_pending_EXTI()

Clears the EXTI pending-request bit for the given pin's line by writing 1 to it. Must be called inside the corresponding `IRQHandler()` after handling the event — forgetting this causes the ISR to re-trigger immediately (or, in a busy-wait loop checking `is_pending_EXTI()`, causes it to never exit).

```c
void clear_pending_EXTI(PinName_t pinName);
```

**Parameters**

* **pinName**: pin whose EXTI pending bit to clear

**Example code**

```c
void EXTI15_10_IRQHandler(void) {
    if (is_pending_EXTI(BUTTON_PIN)) {
        // ... handle event ...
        clear_pending_EXTI(BUTTON_PIN);
    }
}
```

---

## Stepper Motor (FSM-based)

### Header File

`#include "ecStepper2.h"`

```c
#include "stm32f411xe.h"
#include "ecPinNames.h"
#include "ecRCC2.h"
#include "ecGPIO2.h"
#include "ecSysTick2.h"

#ifndef __EC_STEPPER2_H
#define __EC_STEPPER2_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

// Stepper Mode
#define HALF 0
#define FULL 1
#define DIR_CW 0
#define DIR_CCW 1

// 28BYJ-48 : 64 steps/rev x 1/32 gear = 2048
#define STEP_PER_REV  (64*32)

typedef enum {
    S0, S1, S2, S3, S4, S5, S6, S7
} StateNum;

typedef struct {
    uint32_t next[2];
    uint8_t  out[4];
} StateStepper_t;

void stepper_init(uint32_t mode, PinName_t *pinStepper);
void stepper_speed(uint32_t speedRPM);
void stepper_step(uint32_t steps, uint32_t direction);
void stepper_out(uint32_t state);
void stepper_stop(void);
uint32_t getStepsPerRev(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

### stepper_init()

Selects the FSM state table to use (`fsm_Full` for 4-state full-stepping, `fsm_Half` for 8-state half-stepping) and initializes the 4 coil-driver pins (A, B, A', B') as fast digital outputs. Also records how many FSM steps make up one physical revolution in that mode (`STEP_PER_REV` for `FULL`, `STEP_PER_REV*2` for `HALF`) into an internal `stepsPerRev` variable, which `stepper_speed()` and `getStepsPerRev()` then use — so switching between `FULL` and `HALF` here is enough to keep both the speed calculation and the step count correct, without changing anything else in `main()`. Must be called before any other `stepper_*()` function.

```c
void stepper_init(uint32_t mode, PinName_t *pinStepper);
```

**Parameters**

* **mode**: `FULL` (1) or `HALF` (0)
* **pinStepper**: pointer to a 4-element `PinName_t` array, in order `{A, B, A', B'}`

**Example code**

```c
PinName_t pinStepper[4] = {PB_10, PB_4, PB_5, PB_3};
stepper_init(FULL, pinStepper);
```

### stepper_speed()

Converts a desired speed in rpm into the per-step delay (`_step_delay`, in ms) used by `stepper_step()`, using `stepsPerRev` (set by `stepper_init()`) as the steps-per-revolution count. Because `stepsPerRev` already reflects the current mode (`FULL` or `HALF`), the same `speedRPM` value produces the correct real-world rpm in either mode — no manual compensation is needed when switching modes.

```c
void stepper_speed(uint32_t speedRPM);
```

**Parameters**

* **speedRPM**: desired motor speed in revolutions per minute (integer ≥ 1 — passing `0` causes a divide-by-zero)

**Example code**

```c
stepper_speed(1);   // 1 rpm
```

### stepper_step()

Runs the motor for `steps` FSM transitions in the given direction, advancing the FSM state and driving the output pins via `stepper_out()` once per step, with a `_step_delay` ms pause between steps. Does nothing if `stepper_init()` has not been called yet.

```c
void stepper_step(uint32_t steps, uint32_t direction);
```

**Parameters**

* **steps**: number of FSM state transitions to run
* **direction**: `DIR_CW` (0) or `DIR_CCW` (1)

**Example code**

```c
uint32_t steps = STEP_PER_REV*1;   // 1 revolution, full-stepping
stepper_step(steps, DIR_CW);
```

### stepper_out()

Writes the (A, B, A', B') output pattern of the given FSM state to the 4 coil pins. Normally called internally by `stepper_step()`, but can be called directly to force a specific state's output.

```c
void stepper_out(uint32_t state);
```

**Parameters**

* **state**: FSM state index (`S0`–`S3` for full-stepping, `S0`–`S7` for half-stepping)

**Example code**

```c
stepper_out(S0);
```

### stepper_stop()

Immediately de-energizes all 4 coil pins (drives them `LOW`) and resets the internal step counter. Does not reset the current FSM state, so the next `stepper_step()` call resumes from where it left off.

```c
void stepper_stop(void);
```

**Parameters**

* (none)

### getStepsPerRev()

Returns the number of FSM steps needed for one physical revolution in the mode last passed to `stepper_init()` — `STEP_PER_REV` for `FULL`, `STEP_PER_REV*2` for `HALF`. Meant to be used in place of hard-coding `STEP_PER_REV` (or `STEP_PER_REV*2`) when computing a step count for `stepper_step()`, so that `main()` does not need to know which mode is active.

```c
uint32_t getStepsPerRev(void);
```

**Parameters**

* (none)

**Returns**: steps required for 1 revolution in the current mode

**Example code**

```c
stepper_init(HALF, pinStepper);
stepper_speed(1);   // 1 rpm — correct in either mode, no manual compensation needed

uint32_t rev = 1;
uint32_t steps = getStepsPerRev()*rev;   // automatically 2048 (FULL) or 4096 (HALF)
stepper_step(steps, DIR_CW);
```

**Example code**

```c
void EXTI15_10_IRQHandler(void) {
    if (is_pending_EXTI(BUTTON_PIN)) {
        stepper_stop();
        clear_pending_EXTI(BUTTON_PIN);
    }
}
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
