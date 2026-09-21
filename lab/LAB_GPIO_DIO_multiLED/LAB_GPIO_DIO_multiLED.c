/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : Song Jimyeong
Created          : 05-03-2021
Modified         : 09-19-2026 
Language/ver     : C++ in VS Code

Description      : Problem 3 - Toggle multiple LEDs with a button
/----------------------------------------------------------------*/

#include "ecRCC2.h"
#include "ecGPIO2.h"

#define BUTTON_PIN  PA_4

PinName_t LedPin[4] = {PB_12, PB_13, PB_14, PB_15};

// Initialiization 
void setup(void) {
	RCC_HSI_init();
	// initialize the pushbutton pin as an input:
	GPIO_init(BUTTON_PIN, INPUT);  
    GPIO_pupd(BUTTON_PIN, PULL_UP);

	// initialize the LED pin as an output:
    for(int i = 0; i<4; i++){
        GPIO_init(LedPin[i], OUTPUT);
        GPIO_otype(LedPin[i], OPEN_DRAIN);
        GPIO_pupd(LedPin[i], PULL_UP);
        GPIO_ospeed(LedPin[i], MEDIUM_SPEED);
    }
    
}
	

int main(void) {
    setup();

    int ledIndex = 0;
    int buttonState = HIGH;
    int prevButtonState = HIGH;
 
    while (1) {
        buttonState = GPIO_read(BUTTON_PIN);

        if (prevButtonState == HIGH && buttonState == LOW) {
            ledIndex = (ledIndex + 1) % 4;
        }


        for (int i = 0; i < 4; i++) {
            if (i == ledIndex)
                GPIO_write(LedPin[i], HIGH);   
            else
                GPIO_write(LedPin[i], LOW);
        }

        prevButtonState = buttonState;
        delay_ms_HSI(10);
    }
}