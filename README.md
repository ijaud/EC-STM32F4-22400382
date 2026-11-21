---
description: EC_HAL API
---


# Embedded Controller - STM32f411 HAL API

Documentation for HAL functions

Written by:   Jimyeong Song

Course:  Embedded Controller

Program: C/C++

IDE/Compiler: VS Code + PlatformIO

OS: Win10

MCU:  STM32F411RE (Nucleo-64)



---

## Table of Contents

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
  * [Timer Input Capture (ICAP)](#timer-input-capture-icap)
    + [Header File](#header-file-8)
    + [ICAP_init\(\)](#icap_init)
    + [ICAP_ICn_init\(\)](#icap_icn_init)
    + [ICAP_tick\(\)](#icap_tick)
    + [ICAP_read\(\)](#icap_read)
    + [is_CCIF\(\) / clear_CCIF\(\)](#is_ccif--clear_ccif)
    + [ICAP_filter\(\)](#icap_filter)
    + [ICAP_ICn_select\(\)](#icap_icn_select)
    + [ICAP_pinmap\(\)](#icap_pinmap)
  * [ADC (Analog-to-Digital Converter)](#adc-analog-to-digital-converter)
    + [Header File](#header-file-9)
    + [ADC_init\(\)](#adc_init)
    + [ADC_read_poll\(\)](#adc_read_poll)
    + [ADC_read\(\)](#adc_read)
    + [ADC_trigger_init\(\)](#adc_trigger_init)
    + [JADC_init\(\)](#jadc_init)
    + [JADC_read_poll\(\)](#jadc_read_poll)
    + [JADC_read\(\)](#jadc_read)
    + [JADC_trigger_init\(\)](#jadc_trigger_init)
    + [ADC_EOC_enable\(\) / ADC_EOC_disable\(\)](#adc_eoc_enable--adc_eoc_disable)
    + [ADC_start\(\) / ADC_stop\(\)](#adc_start--adc_stop)
    + [ADC_sequence\(\)](#adc_sequence)
    + [ADC_conversion\(\)](#adc_conversion)
    + [is_ADC_EOC\(\) / clear_ADC_EOC\(\)](#is_adc_eoc--clear_adc_eoc)
    + [is_ADC_OVR\(\) / clear_ADC_OVR\(\)](#is_adc_ovr--clear_adc_ovr)
    + [JADC_JEOC_enable\(\) / JADC_JEOC_disable\(\)](#jadc_jeoc_enable--jadc_jeoc_disable)
    + [JADC_start\(\)](#jadc_start)
    + [JADC_sequence\(\)](#jadc_sequence)
    + [is_ADC_JEOC\(\) / clear_ADC_JEOC\(\)](#is_adc_jeoc--clear_adc_jeoc)
    + [ADC_pinmap\(\)](#adc_pinmap)
  * [DHT11 (Temperature / Humidity Sensor)](#dht11-temperature--humidity-sensor)
    + [Header File](#header-file-10)
    + [DHT11_init\(\)](#dht11_init)
    + [DHT11_read\(\)](#dht11_read)
    + [DHT11_temperature\(\) / DHT11_humidity\(\)](#dht11_temperature--dht11_humidity)
  * [I2C and I2C LCD](#i2c-and-i2c-lcd)
    + [Header File](#header-file-11)
    + [I2C1_init\(\) / I2C2_init\(\) / I2C3_init\(\)](#i2c1_init--i2c2_init--i2c3_init)
    + [I2C1_write\(\) / I2C2_write\(\) / I2C3_write\(\)](#i2c1_write--i2c2_write--i2c3_write)
    + [I2C1_read\(\) / I2C2_read\(\) / I2C3_read\(\)](#i2c1_read--i2c2_read--i2c3_read)
    + [LCD_init\(\)](#lcd_init)
    + [LCD_command\(\) / LCD_data\(\)](#lcd_command--lcd_data)
    + [LCD_setCursor\(\)](#lcd_setcursor)
    + [LCD_print\(\)](#lcd_print)

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
#define FAST_SPEED		0x02
#define HIGH_SPEED		0x03

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
* **speed**: `LOW_SPEED` (0x00), `MEDIUM_SPEED` (0x01), `FAST_SPEED` (0x02), `HIGH_SPEED` (0x03)

> OSPEEDR uses 2 bits per pin, and `GPIO_ospeed()` writes `speed << (2*pin)`. The value must therefore be 0–3; a larger value (e.g. `0x10`) would overwrite the speed bits of other pins.

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

> **Note: handler name by EXTI line.** The handler is chosen by the pin **number**, and lines 5 ~ 9 and 10 ~ 15 share one handler. Inside a shared handler, check `is_pending_EXTI()` to find the pin that caused it. A wrong handler name compiles without error, but the interrupt falls into `Default_Handler` and the board appears to freeze.
>
> | EXTI line (pin number) | Handler |
> | --- | --- |
> | 0 ~ 4 | `EXTI0_IRQHandler` ~ `EXTI4_IRQHandler` |
> | 5 ~ 9 | `EXTI9_5_IRQHandler` |
> | 10 ~ 15 | `EXTI15_10_IRQHandler` (e.g. `PC_13` = B1) |

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

**Example code**

```c
void EXTI15_10_IRQHandler(void) {
    if (is_pending_EXTI(BUTTON_PIN)) {
        stepper_stop();
        clear_pending_EXTI(BUTTON_PIN);
    }
}
```

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

------

## USART (Serial Communication)

### Header File

`#include "ecUSART2.h"`

```c
#define BAUD_9600	9600
#define BAUD_19200	19200
#define BAUD_38400  38400
#define BAUD_57600	57600
#define BAUD_115200 115200
#define BAUD_921600 921600

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

```c
USART_init(USART6, PA_11, PA_12, BAUD_9600);  // Bluetooth module : PA11 = TXD, PA12 = RXD (AF8)
```

> **Note:** `USART_init()` (and `USART1_init()` / `USART2_init()`) enable the **RXNE interrupt**. The matching `USARTx_IRQHandler()` must read `DR` (with `USART_read()`) every time, even if the byte is not used; otherwise RXNE never clears and the ISR re-enters forever. The RX pin is configured without pull-up; if the RX line can be left unconnected (e.g. a Bluetooth module that is unplugged), add `GPIO_pupd(rx_pin, PULL_UP)` **after** `USART_init()` so that noise is not read as data.

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

> **Note:** `USART_write()` is **blocking**: it waits for TXE before every byte, adds `USART_delay()`, and waits for TC at the end. At 9600 baud one byte takes about 1 ms, so a 30-character message blocks for about 30 ms. Do not call it (or `printf`) inside an interrupt handler.

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

> **Note: handler names.** Most timers use `TIMx_IRQHandler()`, but **TIM1 has no `TIM1_IRQHandler`**: its update interrupt is `TIM1_UP_TIM10_IRQHandler()` (shared with TIM10). Likewise TIM9 uses `TIM1_BRK_TIM9_IRQHandler()` and TIM11 uses `TIM1_TRG_COM_TIM11_IRQHandler()`. `get_TIM_IRQn()` shows which IRQ each timer uses; the handler name is the IRQ name with `_IRQn` replaced by `_IRQHandler`.
>
> ```c
> TIM_UI_init(TIM1, 500);                  // 500 msec control tick
>
> void TIM1_UP_TIM10_IRQHandler(void){
>     if(is_UIF(TIM1)){
>         flag_tick = 1;                   // only set a flag, do the work in main()
>         clear_UIF(TIM1);
>     }
> }
> ```

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

> **Note:** The counter starts with a **50 % duty** right after `PWM_init()`. For a motor, fan, LED or servo that must start OFF/closed, write the safe value immediately after the init:
>
> ```c
> PWM_init(PA_15, 1);                      // fan, 1 kHz
> PWM_duty(PA_15, 0.0f);                   // start OFF
>
> PWM_init(PC_7, 20);                      // servo, 50 Hz
> PWM_pulsewidth_us(PC_7, 1400);           // start at the closed position
> ```

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

---

## Timer Input Capture (ICAP)

### Header File

`#include "ecICAP2.h"`

```c
#include "stm32f411xe.h"
#include "ecRCC2.h"
#include "ecGPIO2.h"
#include "ecTIM2.h"

#ifndef __EC_ICAP2_H
#define __EC_ICAP2_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// Edge Type
#define IC_RISE 0
#define IC_FALL 1
#define IC_BOTH 2

// Input Capture Number
#define IC_1 1
#define IC_2 2
#define IC_3 3
#define IC_4 4

// Input Capture Filter
#define IC_FILTER_0		0		// no filter, transition sampled at fDTS
#define IC_FILTER_1		1		// N = 2 samples at fCK_INT
#define IC_FILTER_2		2		// N = 4 samples at fCK_INT
#define IC_FILTER_3		3		// N = 8 samples at fCK_INT

// Timer Input Capture Initialization
void ICAP_init(PinName_t pinName, uint32_t edge_type);
void ICAP_ICn_init(PinName_t pinName, uint32_t edge_type, uint32_t ICn);
void ICAP_tick(PinName_t pinName, uint32_t usec);   // CALL THIS LAST
uint32_t ICAP_read(PinName_t pinName, uint32_t ICn);

// Capture/Compare Interrupt Flag
uint32_t is_CCIF(TIM_TypeDef *TIMx, uint32_t ICn);
void clear_CCIF(TIM_TypeDef *TIMx, uint32_t ICn);

// Internal Functions
void ICAP_pinmap(PinName_t pinName, TIM_TypeDef **TIMx, int *chN);
void ICAP_filter(TIM_TypeDef *TIMx, uint32_t ICn, uint16_t filterOpt);
void ICAP_ICn_select(TIM_TypeDef *TIMx, uint32_t TIn, uint32_t ICn);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

> **Note:** A single `PinName_t` selects the GPIO pin, the timer and the channel (TIn) through `ICAP_pinmap()`. Call `RCC_PLL_init()` first, since the tick depends on `EC_SYSCLK`. Initialization order matters: `ICAP_init()` → `ICAP_ICn_init()` (if a second edge/channel is needed) → `ICAP_tick()` **last**, because `ICAP_ICn_init()` resets the tick to 1 usec.

**Supported pins (`ICAP_pinmap()`)**

| Timer | CH1 | CH2 | CH3 | CH4 | AF |
| --- | --- | --- | --- | --- | --- |
| TIM1 | PA8 | PA9 | PA10 | – | AF1 |
| TIM2 | PA0, PA5, PA15 | PA1, PB3 | PB10 | – | AF1 |
| TIM3 | PA6, PB4, PC6 | PB5, PC7 | PC8 | PC9 | AF2 |
| TIM4 | PB6 | PB7 | PB8 | PB9 | AF2 |

### ICAP_init()

Initializes a pin as an input capture channel with the default setting **TIn = ICn** (e.g. `PB_6` = TIM4_CH1 = IC1) and a 1 usec tick. Internally calls `ICAP_ICn_init()` with the channel found by `ICAP_pinmap()`.

```c
void ICAP_init(PinName_t pinName, uint32_t edge_type);
```

**Parameters**

* **pinName**: input capture pin, e.g. `PB_6`
* **edge_type**: `IC_RISE` (0), `IC_FALL` (1), `IC_BOTH` (2)

**Example code**

```c
ICAP_init(PB_6, IC_RISE);    // TIM4_CH1 = IC1, capture on rising edge
```

### ICAP_ICn_init()

Configures one input capture channel `ICn` for the pin: sets the pin to Alternate Function (no pull, high speed) with the AFR bits of the timer, starts the timer with its update interrupt, maps the input TIn to `ICn` (`CCMRx.CCnS`), sets the input filter (`IC_FILTER_3`, N = 8), selects the active edge (`CCER.CCnP/CCnNP`), enables the capture (`CCER.CCnE`), enables the capture/compare interrupt (`DIER.CCnIE`) and the update interrupt (`DIER.UIE`), and starts the counter.

If `ICn` is different from the pin's own channel, the same pin is connected to another IC (`CCnS = 10`). This allows measuring a pulse width with **one pin**: IC1 for the rising edge and IC2 for the falling edge.

```c
void ICAP_ICn_init(PinName_t pinName, uint32_t edge_type, uint32_t ICn);
```

**Parameters**

* **pinName**: input capture pin
* **edge_type**: `IC_RISE`, `IC_FALL`, `IC_BOTH`
* **ICn**: input capture number, `IC_1` ~ `IC_4`

**Example code**

```c
ICAP_init(PB_6, IC_RISE);                // IC1 : rising edge
ICAP_ICn_init(PB_6, IC_FALL, IC_2);      // IC2 : falling edge of the same pin
```

### ICAP_tick()

Sets the counter tick (time of one count) in usec by changing the prescaler: `PSC = usec * EC_SYSCLK / 1,000,000 - 1`. ARR is set to its maximum (`0xFFFF`, or `0xFFFFFFFF` for TIM2/TIM5) and an update event is generated so that the new PSC takes effect. **Call this last**, after all `ICAP_init()` / `ICAP_ICn_init()` calls. `PSC` is 16-bit, so the usable range is 1 ~ about 780 usec at 84 MHz.

```c
void ICAP_tick(PinName_t pinName, uint32_t usec);
```

**Parameters**

* **pinName**: input capture pin (selects the timer)
* **usec**: one tick in usec (0 is raised to 1)

**Example code**

```c
ICAP_tick(PB_6, 10);     // 1 count = 10 usec (0.1 MHz), counter wraps every 65536 x 10 usec = 655 msec
```

### ICAP_read()

Returns the captured counter value (`TIMx->CCRn`) of channel `ICn`. Reading `CCRn` also clears the `CCnIF` flag.

```c
uint32_t ICAP_read(PinName_t pinName, uint32_t ICn);
```

**Parameters**

* **pinName**: input capture pin (selects the timer)
* **ICn**: `IC_1` ~ `IC_4`

**Returns**: captured counter value (in ticks)

**Example code**

```c
cap_prev = ICAP_read(PB_6, IC_1);
```

### is_CCIF() / clear_CCIF()

`is_CCIF()` returns the capture/compare interrupt flag `SR.CCnIF` of channel `ICn`; `clear_CCIF()` clears it. Inside a timer ISR, use it to find out which channel caused the interrupt.

```c
uint32_t is_CCIF(TIM_TypeDef *TIMx, uint32_t ICn);
void clear_CCIF(TIM_TypeDef *TIMx, uint32_t ICn);
```

**Parameters**

* **TIMx**: timer base pointer
* **ICn**: `IC_1` ~ `IC_4`

**Returns** (`is_CCIF`): non-zero if a capture occurred, `0` otherwise

**Example code**

```c
void TIM4_IRQHandler(void){
    if(is_UIF(TIM4)){ ovf_cnt++; clear_UIF(TIM4); }       // counter overflow
    if(is_CCIF(TIM4, IC_1)){ cap_prev = ICAP_read(PB_6, IC_1); ovf_cnt = 0; }   // rising edge
    if(is_CCIF(TIM4, IC_2)){                                                    // falling edge
        cap_curr = ICAP_read(PB_6, IC_2);
        counts = (cap_curr - cap_prev) + ovf_cnt * 65536;     // pulse width in ticks
    }
}
```

### ICAP_filter()

Internal helper that sets the input capture filter (`CCMRx.ICnF`) of one channel only, so that output channels of the same timer are not disturbed. `IC_FILTER_0` = no filter, `IC_FILTER_1/2/3` = N = 2/4/8 samples at fCK_INT.

```c
void ICAP_filter(TIM_TypeDef *TIMx, uint32_t ICn, uint16_t filterOpt);
```

### ICAP_ICn_select()

Internal helper that connects the timer input `TIn` to the capture channel `ICn` (`CCMRx.CCnS`): `01` if `ICn == TIn` (direct), `10` if different (indirect).

```c
void ICAP_ICn_select(TIM_TypeDef *TIMx, uint32_t TIn, uint32_t ICn);
```

### ICAP_pinmap()

Internal helper that returns the timer and channel number (TIn) of an input capture pin (see the pin table above). Pins not in the table leave the outputs unchanged.

```c
void ICAP_pinmap(PinName_t pinName, TIM_TypeDef **TIMx, int *chN);
```

**Parameters**

* **pinName**: pin name
* **TIMx** (out): matching timer base pointer
* **chN** (out): matching channel number

---

## ADC (Analog-to-Digital Converter)

### Header File

`#include "ecADC2.h"`

```c
#include <stdint.h>
#include "stm32f411xe.h"
#include "ecPinNames.h"
#include "ecRCC2.h"
#include "ecGPIO2.h"
#include "ecTIM2.h"

#ifndef __EC_ADC2_H
#define __EC_ADC2_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

// Trigger edge for ADC_trigger_init() / JADC_trigger_init()
#define ADC_RISE		1
#define ADC_FALL		2
#define ADC_BOTH		3

// Repetition for ADC_conversion()
#define ADC_SINGLE		0		// one conversion per trigger
#define ADC_CONT		1		// keep converting after the first trigger

// Regular group
void ADC_init(PinName_t pinName);
uint32_t ADC_read_poll(void);
uint32_t ADC_read(void);
int ADC_trigger_init(TIM_TypeDef *TIMx, uint32_t msec, uint32_t edge);

// Injected group (JADC)
void JADC_init(PinName_t pinName);
uint32_t JADC_read_poll(void);
uint32_t JADC_read(uint32_t JDRn);
int JADC_trigger_init(TIM_TypeDef *TIMx, uint32_t msec, uint32_t edge);

// Interrupt, SW start, multi-channel configuration
void ADC_EOC_enable(void);
void ADC_EOC_disable(void);
void ADC_start(void);
void ADC_stop(void);
void ADC_sequence(PinName_t *seqCHn, uint32_t seqCHnums);
void ADC_conversion(uint32_t convMode);
uint32_t is_ADC_EOC(void);
void clear_ADC_EOC(void);
uint32_t is_ADC_OVR(void);
void clear_ADC_OVR(void);

void JADC_JEOC_enable(void);
void JADC_JEOC_disable(void);
void JADC_start(void);
void JADC_sequence(PinName_t *seqCHn, uint32_t seqCHnums);
uint32_t is_ADC_JEOC(void);
void clear_ADC_JEOC(void);

// Internal
void ADC_pinmap(PinName_t pinName, uint32_t *chN);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
```

> **Note:** Only **ADC1** is used. The ADC clock is PCLK2 / 2 = 42 MHz, the resolution is 12-bit (0 ~ 4095), and every channel is sampled for 84 ADC cycles (2 usec). The **regular group** converts one sequence and puts each result in `DR`; the **injected group (JADC)** converts up to 4 channels and keeps each result in its own register `JDR1` ~ `JDR4`. Both groups share **one interrupt**, `ADC_IRQHandler()`, so check `is_ADC_EOC()` / `is_ADC_JEOC()` inside it.

**Supported pins (`ADC_pinmap()`)**

| Pin | PA0 | PA1 | PA4 | PA5 | PA6 | PA7 | PB0 | PB1 | PC0 | PC1 | PC2 | PC3 | PC4 | PC5 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Channel | 0 | 1 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |

### ADC_init()

Initializes a pin as an analog input for the **regular group**: sets the pin to `ANALOG` with no pull-up/down, enables the ADC1 clock, sets the prescaler (PCLK2/2), 12-bit resolution and 84-cycle sampling time, puts the channel as the only conversion of the sequence, sets EOC after every conversion (`EOCS = 1`), and enables the ADC. The default is software trigger, single conversion, no interrupt.

```c
void ADC_init(PinName_t pinName);
```

**Parameters**

* **pinName**: analog input pin (see the pin table above)

**Example code**

```c
ADC_init(PB_0);              // ADC1 channel 8
```

### ADC_read_poll()

Starts one software-triggered conversion, waits for EOC, and returns the result. For the software-trigger mode only (without `ADC_trigger_init()`).

```c
uint32_t ADC_read_poll(void);
```

**Returns**: conversion result, 0 ~ 4095

**Example code**

```c
ADC_init(PB_0);
uint32_t value = ADC_read_poll();
```

### ADC_read()

Returns the regular-group result in `DR`. Reading `DR` also clears EOC. Use it inside `ADC_IRQHandler()` after `is_ADC_EOC()`.

```c
uint32_t ADC_read(void);
```

**Returns**: conversion result, 0 ~ 4095

### ADC_trigger_init()

Starts the regular-group conversion from a **timer update event (TRGO)** every `msec`, and enables the EOC interrupt. On the F411 only **TIM2** (`EXTSEL = 0110`) and **TIM3** (`EXTSEL = 1000`) can trigger the regular group. The timer is configured with `TIM_init()` and `CR2.MMS = 010` (update event as TRGO).

```c
int ADC_trigger_init(TIM_TypeDef *TIMx, uint32_t msec, uint32_t edge);
```

**Parameters**

* **TIMx**: `TIM2` or `TIM3`
* **msec**: conversion period
* **edge**: `ADC_RISE`, `ADC_FALL`, `ADC_BOTH`

**Returns**: `0` on success, `-1` if `TIMx` cannot trigger the regular group

**Example code**

```c
ADC_init(PB_0);
ADC_trigger_init(TIM3, 1, ADC_RISE);     // convert every 1 msec

void ADC_IRQHandler(void){
    if(is_ADC_OVR()) clear_ADC_OVR();
    if(is_ADC_EOC()){
        value = ADC_read();              // reading DR clears EOC
    }
}
```

### JADC_init()

Initializes a pin as an analog input for the **injected group**: sets the pin to `ANALOG`, enables ADC1, sets 12-bit right alignment and 84-cycle sampling, and builds a one-channel injected sequence. The injected sequence is **right-aligned**: with `JL = 0` the channel is written to `JSQ4`, and its result lands in `JDR1`. The default is software trigger, no interrupt.

```c
void JADC_init(PinName_t pinName);
```

**Parameters**

* **pinName**: analog input pin

**Example code**

```c
JADC_init(PA_0);
```

### JADC_read_poll()

Starts one software-triggered injected conversion (`JSWSTART`), waits for JEOC, reads `JDR1`, and clears JEOC.

```c
uint32_t JADC_read_poll(void);
```

**Returns**: conversion result of the first injected conversion, 0 ~ 4095

### JADC_read()

Returns the result of the n-th conversion of the injected sequence. **Reading `JDRx` does NOT clear JEOC** (unlike `DR`/EOC), so call `clear_ADC_JEOC()` yourself.

```c
uint32_t JADC_read(uint32_t JDRn);
```

**Parameters**

* **JDRn**: **index** of the injected result register, 1 ~ 4 (not a pin name)

**Returns**: conversion result, 0 ~ 4095 (`0` for an invalid index)

**Example code**

```c
light = JADC_read(1);        // JDR1
moist = JADC_read(2);        // JDR2
```

### JADC_trigger_init()

Starts the injected-group conversion from a **timer update event (TRGO)** every `msec`, and enables the JEOC interrupt. The timer is configured with `TIM_init()` and `CR2.MMS = 010`.

| TIMx | JEXTSEL |
| --- | --- |
| TIM1 TRGO | 0001 |
| TIM2 TRGO | 0011 |
| TIM4 TRGO | 1001 |
| TIM5 TRGO | 1011 |

```c
int JADC_trigger_init(TIM_TypeDef *TIMx, uint32_t msec, uint32_t edge);
```

**Parameters**

* **TIMx**: `TIM1`, `TIM2`, `TIM4` or `TIM5`
* **msec**: conversion period
* **edge**: `ADC_RISE`, `ADC_FALL`, `ADC_BOTH`

**Returns**: `0` on success, `-1` if `TIMx` cannot trigger the injected group

**Example code** (two channels, TIM5 every 125 msec)

```c
JADC_init(PA_0);
JADC_init(PA_1);
PinName_t jseq[2] = {PA_0, PA_1};        // [0] -> JDR1, [1] -> JDR2
JADC_sequence(jseq, 2);                  // AFTER all JADC_init() calls
JADC_trigger_init(TIM5, 125, ADC_RISE);  // LAST

void ADC_IRQHandler(void){
    if(is_ADC_JEOC()){
        light = JADC_read(1);
        moist = JADC_read(2);
        clear_ADC_JEOC();                // must clear, or the ISR re-enters forever
    }
}
```

> **Note:** Initialization order matters: every `JADC_init()` resets the injected sequence to one channel, so call `JADC_sequence()` **after** all `JADC_init()` calls, and `JADC_trigger_init()` last.

### ADC_EOC_enable() / ADC_EOC_disable()

Enables/disables the EOC interrupt (`CR1.EOCIE`) and the NVIC `ADC_IRQn` (priority 2). `ADC_EOC_enable()` clears the status register first so that a stale flag does not enter the ISR.

```c
void ADC_EOC_enable(void);
void ADC_EOC_disable(void);
```

### ADC_start() / ADC_stop()

`ADC_start()` clears a latched OVR, sets `ADON` and starts a regular conversion by software (`SWSTART`). `ADC_stop()` clears `ADON`, which also stops timer-triggered conversions.

```c
void ADC_start(void);
void ADC_stop(void);
```

### ADC_sequence()

Builds a multi-channel **regular** sequence: sets `SCAN` mode (when more than 1 channel), the sequence length `L`, and the channels in `SQR3` / `SQR2` / `SQR1` in the given order.

```c
void ADC_sequence(PinName_t *seqCHn, uint32_t seqCHnums);
```

**Parameters**

* **seqCHn**: array of analog pins in conversion order
* **seqCHnums**: number of channels (1 ~ 16)

### ADC_conversion()

Selects single or continuous conversion for the regular group (`CR2.CONT`).

```c
void ADC_conversion(uint32_t convMode);
```

**Parameters**

* **convMode**: `ADC_SINGLE` (0) or `ADC_CONT` (1)

### is_ADC_EOC() / clear_ADC_EOC()

Returns / clears the regular-group end-of-conversion flag (`SR.EOC`).

```c
uint32_t is_ADC_EOC(void);
void clear_ADC_EOC(void);
```

### is_ADC_OVR() / clear_ADC_OVR()

Returns / clears the overrun flag (`SR.OVR`). OVR is set when a conversion finishes before the previous result was read; while it is set the ADC stays silent, so it must be cleared.

```c
uint32_t is_ADC_OVR(void);
void clear_ADC_OVR(void);
```

### JADC_JEOC_enable() / JADC_JEOC_disable()

Enables/disables the JEOC interrupt (`CR1.JEOCIE`) and the NVIC `ADC_IRQn`. Because `ADC_IRQn` is shared with the regular group, `JADC_JEOC_disable()` turns off the NVIC line only when the EOC interrupt is also off.

```c
void JADC_JEOC_enable(void);
void JADC_JEOC_disable(void);
```

### JADC_start()

Sets `ADON` and starts an injected conversion by software (`JSWSTART`). Not needed with `JADC_trigger_init()`.

```c
void JADC_start(void);
```

### JADC_sequence()

Builds a multi-channel **injected** sequence of 1 ~ 4 channels. The sequence is right-aligned in `JSQR`; conversion `i` lands in `JDR(i+1)`.

```c
void JADC_sequence(PinName_t *seqCHn, uint32_t seqCHnums);
```

**Parameters**

* **seqCHn**: array of analog pins in conversion order
* **seqCHnums**: number of channels (1 ~ 4)

### is_ADC_JEOC() / clear_ADC_JEOC()

Returns / clears the injected end-of-conversion flag (`SR.JEOC`). JEOC is cleared **by software only**.

```c
uint32_t is_ADC_JEOC(void);
void clear_ADC_JEOC(void);
```

### ADC_pinmap()

Internal helper that returns the ADC1 channel number of an analog pin (see the pin table above).

```c
void ADC_pinmap(PinName_t pinName, uint32_t *chN);
```

---

## DHT11 (Temperature / Humidity Sensor)

### Header File

`#include "ecDHT11.h"`

```c
#include "stm32f411xe.h"
#include "ecGPIO2.h"
#include "ecRCC2.h"
#include "ecSysTick2.h"

#ifndef __EC_DHT11_H
#define __EC_DHT11_H

// Return codes of DHT11_read()
#define DHT11_OK			 0
#define DHT11_ERR_TOOSOON	-1		// called again before DHT11_MIN_PERIOD_MS
#define DHT11_ERR_NO_REPLY	-2		// the sensor never answered the start pulse
#define DHT11_ERR_TIMEOUT	-3		// a bit edge did not arrive in time
#define DHT11_ERR_CHECKSUM	-4		// 40 bits arrived but the checksum is wrong

#define DHT11_MIN_PERIOD_MS	2000	// datasheet minimum between two reads

void DHT11_init(PinName_t pinName);
int  DHT11_read(void);
int  DHT11_temperature(void);		// degC
int  DHT11_humidity(void);			// %RH

#endif
```

> **Note:** The DHT11 uses a single open-drain data line with an external pull-up. One transaction is about 22 ~ 25 ms: an 18 ms start pulse (interrupts on) and a 3 ~ 5 ms data phase in which **interrupts are disabled**. The microsecond timing reads `SysTick->VAL` directly, so `RCC_PLL_init()` and `SysTick_init()` must be called first. **Never call `DHT11_read()` inside an interrupt handler**; set a flag in a timer ISR and read in `main()`.

### DHT11_init()

Sets the data pin to input with pull-up (idle high) and resets the read history.

```c
void DHT11_init(PinName_t pinName);
```

**Parameters**

* **pinName**: data pin, any plain GPIO pin (e.g. `PA_6`)

**Example code**

```c
DHT11_init(PA_6);
```

### DHT11_read()

Runs one 40-bit transaction: sends the start pulse, waits for the sensor's answer, samples 40 bits (each bit is sampled 40 usec after its rising edge), and checks the checksum. On success the values returned by `DHT11_temperature()` / `DHT11_humidity()` are updated; on failure they keep the last valid values.

```c
int DHT11_read(void);
```

**Returns**

| Code | Value | Meaning |
| --- | --- | --- |
| `DHT11_OK` | 0 | Valid reading |
| `DHT11_ERR_TOOSOON` | -1 | Called less than 2 s after the previous read (not a sensor fault) |
| `DHT11_ERR_NO_REPLY` | -2 | No answer to the start pulse (wiring, power, pull-up) |
| `DHT11_ERR_TIMEOUT` | -3 | A bit edge did not arrive in time |
| `DHT11_ERR_CHECKSUM` | -4 | Data corrupted |

> **Note:** The 2 s minimum is measured from the **end** of the previous read (about 25 ms after it started), and `msTicks` does not count while interrupts are off. Calling it with an exact 2 s timer period therefore returns `DHT11_ERR_TOOSOON` on every other call; use a period slightly longer than 2 s (e.g. 2.5 s).

**Example code**

```c
// TIM1 ISR (500 ms) sets flag_dht every 5 ticks = 2.5 s
if(flag_dht){
    flag_dht = 0;
    int err = DHT11_read();
    if(err == DHT11_OK)
        printf("T = %d C, RH = %d %%\r\n", DHT11_temperature(), DHT11_humidity());
    else
        printf("DHT11 error = %d\r\n", err);
}
```

### DHT11_temperature() / DHT11_humidity()

Return the temperature (degC) and the relative humidity (%) of the **last successful** read. A failed read leaves them unchanged.

```c
int DHT11_temperature(void);
int DHT11_humidity(void);
```

**Returns**: integer temperature [degC] / humidity [%RH]

---

## I2C and I2C LCD

### Header File

`#include "ecI2C2.h"`

```c
#ifndef __EC_I2C2_H
#define __EC_I2C2_H

#include "stm32f411xe.h"
#include "ecGPIO2.h"
#include "ecRCC2.h"

// Pin / AF per bus on the F411R(C-E)T package. Note PB11 does not exist here,
// so I2C2 cannot use the PB10/PB11 pair, and I2C2_SDA is AF9, not AF4.
//   I2C1 : SCL PB_8  (AF4)   SDA PB_9 (AF4)   = the board's SCL/SDA header
//   I2C2 : SCL PB_10 (AF4)   SDA PB_3 or PB_9 (AF9)
//   I2C3 : SCL PA_8  (AF4)   SDA PC_9 (AF4)
// SCL/SDA are open-drain with no internal pull-up : the bus needs external
// pull-ups, which a breakout module normally carries.

// LM75-family temperature sensor (LM75B / TMP75)
#define LM75_ADDR      0x4C
#define LM75_REG_TEMP  0x00
#define LM75_REG_CONF  0x01

// Common LCD definitions
#define LCD_ADDR       0x27
#define LCD_BACKLIGHT  0x08
#define LCD_ENABLE_BIT 0x04
#define LCD_CMD        0x00
#define LCD_DATA       0x01

// ======== I2C1 / I2C2 / I2C3 Functions ========
// Standard mode 100 kHz. CR2/CCR/TRISE are derived from EC_SYSCLK, so the
// bus rate follows RCC_PLL_init() (PCLK1 42MHz) or RCC_HSI_init() (16MHz).
void I2C1_init(void);
void I2C2_init(void);
void I2C3_init(void);

// Returns 0 on success, -1 on timeout (no device, stuck bus, no pull-ups).
int I2C1_write(uint8_t devAddr, uint8_t data);
int I2C2_write(uint8_t devAddr, uint8_t data);
int I2C3_write(uint8_t devAddr, uint8_t data);

// Reads len bytes from the device's current register pointer.
// Returns 0 on success, -1 on timeout or NACK.
int I2C1_read(uint8_t devAddr, uint8_t *buf, uint32_t len);
int I2C2_read(uint8_t devAddr, uint8_t *buf, uint32_t len);
int I2C3_read(uint8_t devAddr, uint8_t *buf, uint32_t len);

// ======== LCD Functions (Using I2C1 by default) ========
void LCD_init(void);
void LCD_command(uint8_t cmd);
void LCD_data(uint8_t data);
void LCD_print(char *str);
void LCD_setCursor(uint8_t col, uint8_t row);

#endif
```

> **Note:** The bus runs in standard mode (**100 kHz**), with SCL and SDA as open-drain AF pins (AF4, or AF9 for the I2C2 SDA). There is **no internal pull-up**: the bus needs external pull-ups, which a breakout module (such as the LCD backpack) normally carries. The LCD functions always use **I2C1**, and the LCD constants are `LCD_ADDR = 0x27`, `LCD_BACKLIGHT = 0x08`, `LCD_ENABLE_BIT = 0x04`, `LCD_CMD = 0x00`, `LCD_DATA = 0x01`. Every write/read is a **blocking** busy-wait. One LCD character needs 6 I2C writes (high nibble + low nibble, each with an enable pulse), about **1.2 ms**, so writing a full 16x2 screen takes about 40 ms. Do not call LCD functions inside interrupt handlers.

### I2C1_init() / I2C2_init() / I2C3_init()

Configures the SCL/SDA pins (AF, open-drain, high speed, AF number chosen by the bus), enables the I2C clock (APB1), and sets the timing registers (`CR2.FREQ`, `CCR`, `TRISE`) for 100 kHz from PCLK1, then enables the peripheral.

```c
void I2C1_init(void);
void I2C2_init(void);
void I2C3_init(void);
```

| Bus | SCL | SDA |
| --- | --- | --- |
| I2C1 | PB_8 (AF4) | PB_9 (AF4) |
| I2C2 | PB_10 (AF4) | PB_3 (AF9) — `I2C2_init()` uses PB_3; PB_9 (AF9) is also possible |
| I2C3 | PA_8 (AF4) | PC_9 (AF4) |

**Example code**

```c
I2C1_init();     // SCL = PB_8, SDA = PB_9
```

### I2C1_write() / I2C2_write() / I2C3_write()

Sends one data byte to a 7-bit device address: START → address (write) → data → STOP. Stops at once on NACK, arbitration loss or bus error.

```c
int I2C1_write(uint8_t devAddr, uint8_t data);
```

**Parameters**

* **devAddr**: 7-bit device address (e.g. `LCD_ADDR` = 0x27)
* **data**: byte to send

**Returns**: `0` on success, `-1` on timeout or error (no device, NACK, stuck bus, missing pull-ups)

**Example code**

```c
int err = I2C1_write(LCD_ADDR, LCD_BACKLIGHT);   // does the LCD answer?
if(err) printf("LCD NOT found\r\n");
```

### I2C1_read() / I2C2_read() / I2C3_read()

Reads `len` bytes from a device (master receiver), handling the 1-, 2- and 3+-byte cases of the reference manual (NACK on the last byte, STOP at the right moment).

```c
int I2C1_read(uint8_t devAddr, uint8_t *buf, uint32_t len);
```

**Parameters**

* **devAddr**: 7-bit device address
* **buf**: buffer for the received bytes
* **len**: number of bytes to read

**Returns**: `0` on success, `-1` on timeout or NACK

Reads from the device's **current register pointer**. To read a specific register, write the register address first with `I2Cx_write()`, then call `I2Cx_read()`.

**Example code** (LM75 temperature sensor)

```c
uint8_t raw[2];
I2C1_write(LM75_ADDR, LM75_REG_TEMP);              // set the register pointer to TEMP
if(I2C1_read(LM75_ADDR, raw, 2) == 0){
    int16_t t = (int16_t)((raw[0] << 8) | raw[1]); // 16-bit two's complement, 1/256 degC
    float tempC = t / 256.0f;
}
```

### LCD_init()

Initializes the HD44780 LCD in 4-bit mode: waits 50 ms for power-up, then sends `0x33`, `0x32` (switch to 4-bit), `0x28` (2 lines, 5x8 dots), `0x0C` (display on, cursor off), `0x06` (increment cursor), `0x01` (clear), and waits 2 ms. Call `I2C1_init()` first.

```c
void LCD_init(void);
```

**Example code**

```c
I2C1_init();
LCD_init();
```

### LCD_command() / LCD_data()

Send one command byte / one character to the LCD (two 4-bit nibbles, each with an enable pulse).

```c
void LCD_command(uint8_t cmd);
void LCD_data(uint8_t data);
```

**Example code**

```c
LCD_command(0x01);   // clear display (slow, about 1.5 ms)
LCD_data('A');
```

### LCD_setCursor()

Moves the cursor to column `col` of row `row` (DDRAM addresses 0x00, 0x40, 0x14, 0x54 for rows 0 ~ 3; a 16x2 LCD uses rows 0 and 1).

```c
void LCD_setCursor(uint8_t col, uint8_t row);
```

**Parameters**

* **col**: column, 0 ~ 15
* **row**: row, 0 ~ 1 (16x2)

### LCD_print()

Prints a null-terminated string from the current cursor position.

```c
void LCD_print(char *str);
```

**Parameters**

* **str**: string to print

**Example code**

```c
char lcd_line[20];
sprintf(lcd_line, "%2d\xDF %2d%% LED %3d%%", temp, humi, duty);   // 0xDF = degree sign
LCD_setCursor(0, 1);
LCD_print(lcd_line);
```

> **Note:** To update a line without flicker, overwrite it with a string padded to 16 characters instead of clearing the screen with `LCD_command(0x01)`. Characters such as `°` typed in a UTF-8 source file do not display correctly; use the HD44780 code (`\xDF` for the degree sign).
