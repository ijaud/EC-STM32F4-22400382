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
  * [USART (Serial Communication)](#usart-serial-communication)
    + [Header File](#header-file-5)
    + [USART_init\(\)](#usart_init)
    + [USART_baud\(\)](#usart_baud)
    + [USART_pins\(\)](#usart_pins)
    + [USART1_baud\(\) / USART2_baud\(\)](#usart1_baud--usart2_baud)
    + [USART1_init\(\) / USART2_init\(\)](#usart1_init--usart2_init)
    + [USART1_write\(\) / USART2_write\(\)](#usart1_write--usart2_write)
    + [USART1_read\(\) / USART2_read\(\)](#usart1_read--usart2_read)
    + [is_USART1_RXNE\(\) / is_USART2_RXNE\(\)](#is_usart1_rxne--is_usart2_rxne)
    + [USART_clock_enable\(\)](#usart_clock_enable)
    + [USART_write\(\)](#usart_write)
    + [USART_read\(\)](#usart_read)
    + [is_USART_RXNE\(\)](#is_usart_rxne)
    + [USART_delay\(\)](#usart_delay)

  * [Timer (TIM) & Update Interrupt](#timer-tim--update-interrupt)
    + [Header File](#header-file-6)
    + [TIM_init\(\) / TIM_init_us\(\)](#tim_init--tim_init_us)
    + [TIM_period\(\) / TIM_period_us\(\)](#tim_period--tim_period_us)
    + [TIM_UI_init\(\) / TIM_UI_init_us\(\)](#tim_ui_init--tim_ui_init_us)
    + [TIM_UI_enable\(\) / TIM_UI_disable\(\)](#tim_ui_enable--tim_ui_disable)
    + [is_UIF\(\) / clear_UIF\(\)](#is_uif--clear_uif)
    + [TIM_clock_enable\(\)](#tim_clock_enable)
    + [get_TIM_IRQn\(\)](#get_tim_irqn)
  * [PWM (Pulse Width Modulation)](#pwm-pulse-width-modulation)
    + [Header File](#header-file-7)
    + [PWM_init\(\) / PWM_init_us\(\)](#pwm_init--pwm_init_us)
    + [PWM_duty\(\)](#pwm_duty)
    + [PWM_pulsewidth\(\) / PWM_pulsewidth_us\(\)](#pwm_pulsewidth--pwm_pulsewidth_us)
    + [PWM_init_config\(\)](#pwm_init_config)
    + [PWM_mode_config\(\)](#pwm_mode_config)
    + [PWM_pinmap\(\)](#pwm_pinmap)

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

## USART (Serial Communication)

### Header File

`#include "ecUSART2.h"`

```c
#define BAUD_9600	9600
#define BAUD_38400  38400
#define BAUD_57600	57600
#define BAUD_115200 115200

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

void USART_init(USART_TypeDef* USARTx, PinName_t pin_GPIO_TX, PinName_t pin_GPIO_RX, uint32_t baud);
void USART_baud(USART_TypeDef* USARTx, uint32_t baud);
void USART_pins(USART_TypeDef* USARTx, PinName_t pin_GPIO_TX, PinName_t pin_GPIO_RX);
void USART1_baud(uint32_t baud);
void USART2_baud(uint32_t baud);

void USART1_init(void);
void USART2_init(void);

void USART1_write(uint8_t* buffer, uint32_t nBytes);
void USART2_write(uint8_t* buffer, uint32_t nBytes);
uint8_t USART1_read(void);
uint8_t USART2_read(void);

uint32_t is_USART1_RXNE(void);
uint32_t is_USART2_RXNE(void);

void USART_clock_enable(USART_TypeDef* USARTx);
void USART_write(USART_TypeDef* USARTx, uint8_t* buffer, uint32_t nBytes);
uint8_t USART_read(USART_TypeDef * USARTx);
uint32_t is_USART_RXNE(USART_TypeDef * USARTx);
void USART_delay(uint32_t us);

#ifdef __cplusplus
}
#endif /* __cplusplus */
```

> **Note:** STM32F411 only has **USART1, USART2, USART6** (no USART3/4/5). USART2 is wired through the ST-Link USB on the NUCLEO board (direct PC connection); USART1 and USART6 are free GPIO-based peripherals for general-purpose serial links (MCU-to-MCU, Bluetooth modules, etc.).

### USART_init()

General-purpose USART configuration for **any** of USART1/USART2/USART6: configures the TX/RX GPIO pins (via `USART_pins()`), sets word length/parity/oversampling/stop bits (no parity, 8-bit, oversampling x16, 1 stop bit), sets the baud rate (via `USART_baud()`), enables TX/RX and the USART peripheral, then enables the RXNE (RX-not-empty) interrupt and picks the matching NVIC IRQ number (`USART1_IRQn`/`USART2_IRQn`/`USART6_IRQn`) for whichever `USARTx` was passed in.

```c
void USART_init(USART_TypeDef* USARTx, PinName_t pin_GPIO_TX, PinName_t pin_GPIO_RX, uint32_t baud);
```

**Parameters**

* **USARTx**: peripheral base pointer — `USART1`, `USART2`, or `USART6`
* **pin_GPIO_TX**: TX pin, e.g. `PA_9`
* **pin_GPIO_RX**: RX pin, e.g. `PA_10`
* **baud**: baud rate, e.g. `BAUD_9600`

**Example code**

```c
USART_init(USART1, PA_9, PA_10, BAUD_9600);   // PA9 = TXD, PA10 = RXD
```

### USART_baud()

Computes and writes the `BRR` (Baud Rate Register) value for the requested baud rate, given the USART peripheral's actual clock (APB2 for USART1/USART6 at 84MHz after `RCC_PLL_init()`, APB1 for USART2 at 42MHz — half the APB2 rate). `USARTDIV = f_CK / (16 * baud)` is split into a Mantissa (`BRR[15:4]`) and a Fraction (`BRR[3:0]`, in 1/16ths), with carry handling in case rounding the fraction overflows into 16.

```c
void USART_baud(USART_TypeDef* USARTx, uint32_t baud);
```

**Parameters**

* **USARTx**: peripheral base pointer — `USART1`, `USART2`, or `USART6`
* **baud**: desired baud rate, e.g. `BAUD_57600`

**Example code**

```c
USART_baud(USART2, BAUD_57600);
```

### USART_pins()

Configures the TX and RX GPIO pins for Alternate Function mode (Push-Pull, No Pull-up/down, High speed) and sets each pin's Alternate Function Register (AFR) bits to select the USART function (AF7 for USART1/USART2, AF8 for USART6).

```c
void USART_pins(USART_TypeDef* USARTx, PinName_t pin_GPIO_TX, PinName_t pin_GPIO_RX);
```

**Parameters**

* **USARTx**: peripheral base pointer, used only to pick AF7 vs AF8
* **pin_GPIO_TX**: TX pin
* **pin_GPIO_RX**: RX pin

**Example code**

```c
USART_pins(USART1, PA_9, PA_10);
```

### USART1_baud() / USART2_baud()

Convenience wrappers around `USART_baud()` for USART1 and USART2 specifically — useful for changing the baud rate after `USART1_init()`/`USART2_init()` already ran at their default (9600).

```c
void USART1_baud(uint32_t baud);
void USART2_baud(uint32_t baud);
```

**Parameters**

* **baud**: new baud rate, e.g. `BAUD_38400`

**Example code**

```c
USART2_init();          // starts at default 9600
USART2_baud(BAUD_38400); // switch to 38400
```

### USART1_init() / USART2_init()

Fixed-pin, fixed-default-baud (9600) initialization for USART1 (PA9=TX, PA10=RX) and USART2 (PA2=TX, PA3=RX). Unlike `USART_init()`, these don't take a `USARTx` parameter — each is hardcoded to its own peripheral, pins, and NVIC IRQ, so no IRQ-selection branch is needed internally. USART2's TX/RX are routed through the NUCLEO board's ST-Link, so `USART2_init()` is what connects the MCU to a PC terminal (e.g. TeraTerm) over the USB cable with no extra wiring.

```c
void USART1_init(void);
void USART2_init(void);
```

**Parameters**

* (none)

**Example code**

```c
USART2_init();   // PC <-> MCU link via ST-Link USB, 9600 baud, RX interrupt enabled
USART1_init();   // MCU <-> MCU (or MCU <-> Bluetooth module) link via PA9/PA10, 9600 baud
```

### USART1_write() / USART2_write()

Transmits `nBytes` from `buffer` over USART1 or USART2, polling the TXE (TX-empty) flag before each byte. Thin wrappers around `USART_write()`.

```c
void USART1_write(uint8_t* buffer, uint32_t nBytes);
void USART2_write(uint8_t* buffer, uint32_t nBytes);
```

**Parameters**

* **buffer**: pointer to the bytes to send
* **nBytes**: number of bytes to send

**Example code**

```c
uint8_t c = 'H';
USART1_write(&c, 1);
```

### USART1_read() / USART2_read()

Blocks until a byte is available (polls `is_USART1_RXNE()`/`is_USART2_RXNE()`) and returns it. Normally called from inside the corresponding `IRQHandler()` right after confirming `is_USARTx_RXNE()` is already set, so the "blocking" wait resolves immediately. Thin wrappers around `USART_read()`.

```c
uint8_t USART1_read(void);
uint8_t USART2_read(void);
```

**Parameters**

* (none)

**Returns**: the received byte

**Example code**

```c
void USART1_IRQHandler(void){
    if (is_USART1_RXNE()){
        uint8_t data = USART1_read();
    }
}
```

### is_USART1_RXNE() / is_USART2_RXNE()

Checks the RXNE (RX-not-empty) flag of USART1/USART2 — `1` if a received byte is waiting in the data register, `0` otherwise. The standard guard at the top of a USART RX interrupt handler, since the same `IRQHandler()` can in principle fire for reasons other than a fresh reception.

```c
uint32_t is_USART1_RXNE(void);
uint32_t is_USART2_RXNE(void);
```

**Parameters**

* (none)

**Returns**: `1` if RXNE is set, `0` otherwise

**Example code**

```c
void USART2_IRQHandler(void){
    if (is_USART2_RXNE()){   // only act on a genuinely new byte
        uint8_t data = USART2_read();
    }
}
```

### USART_clock_enable()

Enables the AHB/APB peripheral clock for the given USART: `RCC_APB2ENR_USART1EN` for USART1, `RCC_APB1ENR_USART2EN` for USART2, `RCC_APB2ENR_USART6EN` for USART6. Called internally by `USART_init()`/`USART1_init()`/`USART2_init()`.

```c
void USART_clock_enable(USART_TypeDef* USARTx);
```

**Parameters**

* **USARTx**: peripheral base pointer — `USART1`, `USART2`, or `USART6`

**Example code**

```c
USART_clock_enable(USART1);
```

### USART_write()

The general-purpose byte-buffer transmit routine underlying `USART1_write()`/`USART2_write()`: for each byte, waits for the TXE flag, writes it to `DR` (which clears TXE), then waits for the TC (transmission-complete) flag after the whole buffer is sent.

```c
void USART_write(USART_TypeDef* USARTx, uint8_t* buffer, uint32_t nBytes);
```

**Parameters**

* **USARTx**: peripheral base pointer
* **buffer**: pointer to the bytes to send
* **nBytes**: number of bytes to send

**Example code**

```c
uint8_t msg[] = "Hello\r\n";
USART_write(USART2, msg, sizeof(msg));
```

### USART_read()

The general-purpose single-byte receive routine underlying `USART1_read()`/`USART2_read()`: blocks until `is_USART_RXNE()` is set, then reads `DR` (which clears RXNE).

```c
uint8_t USART_read(USART_TypeDef * USARTx);
```

**Parameters**

* **USARTx**: peripheral base pointer

**Returns**: the received byte

**Example code**

```c
uint8_t data = USART_read(USART1);
```

### is_USART_RXNE()

The general-purpose RXNE-flag check underlying `is_USART1_RXNE()`/`is_USART2_RXNE()`.

```c
uint32_t is_USART_RXNE(USART_TypeDef * USARTx);
```

**Parameters**

* **USARTx**: peripheral base pointer

**Returns**: `1` if RXNE is set, `0` otherwise

**Example code**

```c
if (is_USART_RXNE(USART2)) { ... }
```

### USART_delay()

A short busy-wait delay (in microseconds) inserted between bytes inside `USART_write()`, to give the receiving side time to process each byte.

```c
void USART_delay(uint32_t us);
```

**Parameters**

* **us**: delay duration in microseconds

**Example code**

```c
USART_delay(300);
```


---

## Timer (TIM) & Update Interrupt

### Header File

`#include "ecTIM2.h"`

```c
#include "stm32f411xe.h"
#include "ecPinNames.h"
#include "ecRCC2.h"
#include "ecGPIO2.h"
#include "math.h"

#ifndef __EC_TIM2_H
#define __EC_TIM2_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

// Timer Update Interrupt Initialization
void TIM_UI_init(TIM_TypeDef* TIMx, uint32_t msec);     // 16-bit  msec < 65,530 msec
void TIM_UI_init_us(TIM_TypeDef* TIMx, uint32_t usec);  // 16-bit  usec < 65,530 usec

// Timer Update Interrupt On/OFf
void TIM_UI_enable(TIM_TypeDef* TIMx);
void TIM_UI_disable(TIM_TypeDef* TIMx);

// Timer Update Interrupt Flag
uint32_t is_UIF(TIM_TypeDef *TIMx);
void clear_UIF(TIM_TypeDef *TIMx);

// Timer Counter Initialization
void TIM_init(TIM_TypeDef *TIMx, uint32_t msec);
void TIM_init_us(TIM_TypeDef *TIMx, uint32_t usec);

// Timer Counter Period Config
void TIM_period(TIM_TypeDef* TIMx, uint32_t msec);
void TIM_period_us(TIM_TypeDef* TIMx, uint32_t usec);

// Timer Counter Auxiliary Functions
uint32_t get_TIM_IRQn(TIM_TypeDef* TIMx);
void TIM_clock_enable(TIM_TypeDef* TIMx);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

> **Note:** The counter clock is derived from `EC_SYSCLK`, so call `RCC_PLL_init()` (or `RCC_HSI_init()`) **before** any `TIM_*` function. The counter clock is `f_cnt = EC_SYSCLK / (PSC + 1)` and the update-event period is `(ARR + 1) / f_cnt`.

### TIM_init() / TIM_init_us()

Enables the timer's peripheral clock, sets the counter period, selects up-counting (`CR1.DIR = 0`), and starts the counter (`CR1.CEN = 1`). Does **not** enable the update interrupt — use `TIM_UI_init()` for that.

* `TIM_init()` uses a fixed counter clock of **10 kHz** (1 count = 0.1 ms), so the period is given in msec (1 ~ 6,553 msec for a 16-bit ARR).
* `TIM_init_us()` uses a fixed counter clock of **1 MHz** (1 count = 1 usec), so the period is given in usec (1 ~ 65,530 usec for a 16-bit ARR).

```c
void TIM_init(TIM_TypeDef* TIMx, uint32_t msec);
void TIM_init_us(TIM_TypeDef* TIMx, uint32_t usec);
```

**Parameters**

* **TIMx**: timer base pointer — `TIM1`, `TIM2`, `TIM3`, `TIM4`, `TIM5`, `TIM9`, `TIM10`, `TIM11`
* **msec** / **usec**: update-event period

**Example code**

```c
TIM_init(TIM3, 500);        // free-running TIM3, update event every 500 msec
TIM_init_us(TIM4, 100);     // free-running TIM4, update event every 100 usec
```

### TIM_period() / TIM_period_us()

Sets only the prescaler (`PSC`) and auto-reload (`ARR`) registers; called internally by `TIM_init()` / `TIM_init_us()`.

```c
void TIM_period(TIM_TypeDef* TIMx, uint32_t msec);
void TIM_period_us(TIM_TypeDef* TIMx, uint32_t usec);
```

| Function | f_cnt | PSC | ARR |
| --- | --- | --- | --- |
| `TIM_period(TIMx, msec)` | 10 kHz | `EC_SYSCLK / 10000 - 1` (84 MHz → 8399) | `(10000 / 1000) * msec - 1` |
| `TIM_period_us(TIMx, usec)` | 1 MHz | `EC_SYSCLK / 1000000 - 1` (84 MHz → 83) | `(1000000 / 1000000) * usec - 1` |

**Parameters**

* **TIMx**: timer base pointer
* **msec** / **usec**: update-event period

**Example code**

```c
TIM_period(TIM2, 20);        // change TIM2's period to 20 msec
```

### TIM_UI_init() / TIM_UI_init_us()

One-call setup of a **timer update interrupt**: starts the counter (`TIM_init()` / `TIM_init_us()`), enables the update interrupt (`TIM_UI_enable()`), enables the timer's NVIC interrupt, and sets its NVIC priority to **2**. After this, the timer's `TIMx_IRQHandler()` runs on every update event.

```c
void TIM_UI_init(TIM_TypeDef* TIMx, uint32_t msec);
void TIM_UI_init_us(TIM_TypeDef* TIMx, uint32_t usec);
```

**Parameters**

* **TIMx**: timer base pointer
* **msec** / **usec**: interrupt period

**Example code**

```c
TIM_UI_init(TIM3, 500);      // TIM3 update interrupt every 500 msec

void TIM3_IRQHandler(void){
    if(is_UIF(TIM3)){
        // ... do something every 500 msec ...
        clear_UIF(TIM3);     // must clear the flag
    }
}
```

### TIM_UI_enable() / TIM_UI_disable()

Enables/disables the update interrupt (`DIER.UIE`) of a timer. `TIM_UI_enable()` first clears any stale UIF flag so that no old event fires immediately.

```c
void TIM_UI_enable(TIM_TypeDef* TIMx);
void TIM_UI_disable(TIM_TypeDef* TIMx);
```

**Parameters**

* **TIMx**: timer base pointer

**Example code**

```c
TIM_UI_disable(TIM3);        // pause the periodic interrupt
TIM_UI_enable(TIM3);         // resume it
```

### is_UIF() / clear_UIF()

`is_UIF()` returns the update-interrupt flag (`SR.UIF`); `clear_UIF()` clears it. The flag must be cleared inside the interrupt handler, otherwise the handler re-enters immediately.

```c
uint32_t is_UIF(TIM_TypeDef *TIMx);
void clear_UIF(TIM_TypeDef *TIMx);
```

**Parameters**

* **TIMx**: timer base pointer

**Returns** (`is_UIF`): non-zero if an update event is pending, `0` otherwise

**Example code**

```c
if(is_UIF(TIM3)){ clear_UIF(TIM3); }
```

### TIM_clock_enable()

Enables the peripheral clock of the given timer: `APB2ENR` for TIM1/TIM9/TIM10/TIM11, `APB1ENR` for TIM2/TIM3/TIM4/TIM5. Called internally by `TIM_init()` / `TIM_init_us()`.

```c
void TIM_clock_enable(TIM_TypeDef* TIMx);
```

**Parameters**

* **TIMx**: timer base pointer

### get_TIM_IRQn()

Returns the NVIC interrupt number for a timer's update interrupt (e.g. `TIM3` → `TIM3_IRQn`, `TIM1` → `TIM1_UP_TIM10_IRQn`). Used by `TIM_UI_init()` to enable the right NVIC channel.

```c
uint32_t get_TIM_IRQn(TIM_TypeDef* TIMx);
```

**Parameters**

* **TIMx**: timer base pointer

**Returns**: IRQ number of the timer's update interrupt

---

## PWM (Pulse Width Modulation)

### Header File

`#include "ecPWM2.h"`

```c
#include "math.h"
#include "stm32f411xe.h"
#include "ecGPIO2.h"
#include "ecTIM2.h"

#ifndef __EC_PWM2_H
#define __EC_PWM2_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/* PWM Output Mode : OCxM field in CCMRx (3 bits) */
#define EC_PWM_MODE1	0	// output active while CNT <  CCR  (default)
#define EC_PWM_MODE2	1	// output active while CNT >= CCR  (inverted)

// Internal helper for PWM initialization
void PWM_init_config(PinName_t pinName, uint32_t usec);
// Duty ratio 0~1.0
void PWM_duty(PinName_t pinName, float duty);

// Low-frequency PWM initialization in msec (default 50% duty, PWM mode 1)
void PWM_init(PinName_t pinName, uint32_t msec);
// High-frequency PWM initialization in usec (default 50% duty, PWM mode 1)
void PWM_init_us(PinName_t pinName, uint32_t usec);

// Set pulse width
void PWM_pulsewidth(PinName_t pinName, uint32_t pulse_width_ms);
void PWM_pulsewidth_us(PinName_t pinName, uint32_t pulse_width_us);

// Internal helpers
void PWM_mode_config(TIM_TypeDef *TIMx, int chN, uint32_t mode);
void PWM_pinmap(PinName_t pinName, TIM_TypeDef **TIMx, int *chN);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

> **Note:** A single `PinName_t` selects the GPIO pin, the timer and the channel. The pin → (timer, channel) mapping is resolved by `PWM_pinmap()` (see table below). Call `RCC_PLL_init()` first, since the PWM period depends on `EC_SYSCLK`. The initial duty ratio is 50%.

**Supported pins (`PWM_pinmap()`)**

| Timer | CH1 | CH2 | CH3 | CH4 | AF |
| --- | --- | --- | --- | --- | --- |
| TIM1 | PA8 | PA9 | PA10 | – | AF1 |
| TIM2 | PA0, PA5, PA15 | PA1, PB3 | PB10 | – | AF1 |
| TIM3 | PA6, PB4, PC6 | PB5, PC7 | PC8 | PC9 | AF2 |
| TIM4 | PB6 | PB7 | PB8 | PB9 | AF2 |

### PWM_init() / PWM_init_us()

Configures a pin as a PWM output with a given **period**: sets the pin to Alternate Function, selects the AF number (AF1 for TIM1/TIM2, AF2 for TIM3/TIM4), initializes the timer, selects PWM mode 1 (active high, 50% duty), and starts the counter. For TIM1, the main output enable (`BDTR.MOE`) is also set.

* `PWM_init()`: period in **msec**, for low frequencies (below 1 kHz). A period of 0 is raised to 1 msec.
* `PWM_init_us()`: period in **usec**, for high frequencies (1 kHz ~ 100 kHz). A period below 10 usec is raised to 10 usec.

Period limits: TIM2/TIM5 have a 32-bit ARR; TIM1/TIM3/TIM4 have a 16-bit ARR, so their period is limited to about 65,536 usec for `PWM_init_us()` and 6,553 msec for `PWM_init()`.

```c
void PWM_init(PinName_t pinName, uint32_t msec);
void PWM_init_us(PinName_t pinName, uint32_t usec);
```

**Parameters**

* **pinName**: PWM output pin, e.g. `PA_0`, `PA_1`
* **msec** / **usec**: PWM period

**Example code**

```c
PWM_init(PA_1, 20);          // 20 msec period (50 Hz) on TIM2_CH2 : RC servo
PWM_init(PA_0, 1);           // 1 msec period (1 kHz)  on TIM2_CH1 : DC motor
PWM_init_us(PA_6, 50);       // 50 usec period (20 kHz) on TIM3_CH1
```

### PWM_duty()

Sets the duty ratio (0.0 ~ 1.0) of a PWM pin. The value is clamped to 0.0 ~ 1.0 and converted to a capture/compare value `CCR = (ARR + 1) * duty` for the pin's channel.

```c
void PWM_duty(PinName_t pinName, float duty);
```

**Parameters**

* **pinName**: PWM pin already initialized with `PWM_init()` / `PWM_init_us()`
* **duty**: duty ratio, 0.0 (always LOW) ~ 1.0 (always HIGH)

**Example code**

```c
PWM_duty(PA_0, 0.5f);        // 50% duty
PWM_duty(PA_0, 1.0f);        // 100% duty
```

### PWM_pulsewidth() / PWM_pulsewidth_us()

Sets the **pulse width (HIGH time)** directly instead of a duty ratio. The function reads the counter clock `f_cnt = EC_SYSCLK / (PSC + 1)`, converts the pulse width to counts, then calls `PWM_duty()` with `counts / (ARR + 1)`. `PWM_init()` / `PWM_init_us()` must be called first so that `PSC` and `ARR` are set.

```c
void PWM_pulsewidth(PinName_t pinName, uint32_t pulse_width_ms);
void PWM_pulsewidth_us(PinName_t pinName, uint32_t pulse_width_us);
```

**Parameters**

* **pinName**: PWM pin
* **pulse_width_ms** / **pulse_width_us**: HIGH time in msec / usec

**Example code**

```c
PWM_init(PA_1, 20);                 // 20 msec period
PWM_pulsewidth_us(PA_1, 1500);      // 1.5 msec pulse -> RC servo at 90 deg
```

### PWM_init_config()

Internal helper called by `PWM_init()` and `PWM_init_us()`, which does the actual setup with the period in usec: matches the timer/channel, sets the pin to AF and writes its AFR bits, initializes the timer (`TIM_init_us()` for TIM2/TIM5 or periods ≤ 65,536 usec, otherwise `TIM_init()` with the period converted to msec and limited to 6,553 msec), configures PWM mode 1, generates an update event, clears the UIF flag and starts the counter.

```c
void PWM_init_config(PinName_t pinName, uint32_t usec);
```

**Parameters**

* **pinName**: PWM output pin
* **usec**: PWM period in usec

### PWM_mode_config()

Internal helper that sets the output-compare mode of one channel: `OCxM = 110` (PWM mode 1, `EC_PWM_MODE1`) or `111` (PWM mode 2, `EC_PWM_MODE2`), enables the CCR preload, sets the default `CCR = ARR/2` (50% duty), selects active-high polarity, and enables the channel output (`CCER.CCxE`).

```c
void PWM_mode_config(TIM_TypeDef *TIMx, int chN, uint32_t mode);
```

**Parameters**

* **TIMx**: timer base pointer
* **chN**: channel number, 1 ~ 4
* **mode**: `EC_PWM_MODE1` (0) or `EC_PWM_MODE2` (1)

### PWM_pinmap()

Internal helper that returns the timer and channel number of a PWM-capable pin (see the pin table above). Pins not in the table leave the outputs unchanged.

```c
void PWM_pinmap(PinName_t pinName, TIM_TypeDef **TIMx, int *chN);
```

**Parameters**

* **pinName**: pin name
* **TIMx** (out): matching timer base pointer
* **chN** (out): matching channel number
