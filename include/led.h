#pragma once
#define LED_PIN 2
#define SLOW_BLINKING_DELAY 2000

/* Todo : Arithmetik in Pre-Prozessor Anweisung schreiben, sodas slow und fast blinking die selbe Zeit dauern
*/

void init_led(void);
void led_on(void);
void led_off(void);
void slow_blinking(void);
void fast_blinking(void);