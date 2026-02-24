#pragma once
#define LED_PIN 2
#define SLOW_BLINKING_DELAY 1000
#define FAST_BLINKING_DELAY 200


/* Todo : Arithmetik in Pre-Prozessor Anweisung schreiben, sodas slow und fast blinking die selbe Zeit dauern
*/
#define LED_PROGRAM_DURATION 10000

typedef enum {
    LED_ON = 1,
    LED_BLINK_SLOW = 2,
    LED_BLINK_FAST = 3,
    LED_OFF = 4
} led_state_t;


void init_led(void);
void led_on(void);
void led_off(void);
void no_blinking(void);
void slow_blinking(void);
void fast_blinking(void);
void led_error_message(led_state_t);