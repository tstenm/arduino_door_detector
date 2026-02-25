#include <Arduino.h>
#include <stdint.h>
#include "led.h"


/*******************************************************************************
 * @brief   Set LED_PIN in output mode
 *
 * @param    void
 *
 * @return  void
 ******************************************************************************/
void init_led(){
    pinMode(LED_PIN, OUTPUT);
}


/*******************************************************************************
 * @brief   Activate LED 
 *
 * @param   void
 *
 * @return  void
 ******************************************************************************/
 void led_on(){
    digitalWrite(LED_PIN, HIGH);
}


/*******************************************************************************
 * @brief   Deactivate LED
 *
 * @param   void
 *
 * @return  void
 ******************************************************************************/
void led_off(){
    digitalWrite(LED_PIN, LOW);
}



/*******************************************************************************
 * @brief   LED is on for LED_PROGRAM_DURATION Milliseconds
 *
 * @param   void
 *
 * @return  void
 ******************************************************************************/
void no_blinking(){
    led_on();
    delay(LED_PROGRAM_DURATION);
}


/*******************************************************************************
 * @brief   Lets LED blink slow for LED_PROGRAM_DURATION Milliseconds
 *
 * @param   void
 *
 * @return  void
 ******************************************************************************/
void slow_blinking(){
    const int LED_SWITCHES = 2;
    int N_ITERATIONS = LED_PROGRAM_DURATION / SLOW_BLINKING_DELAY / LED_SWITCHES ;
    for(int i;i < N_ITERATIONS; i++){
        led_on();
        delay(SLOW_BLINKING_DELAY);
        led_off();
        delay(SLOW_BLINKING_DELAY);
    }
    
}


/*******************************************************************************
 * @brief   Lets LED blink fast for LED_PROGRAM_DURATION Milliseconds
 *
 * @param   void
 *
 * @return  void
 ******************************************************************************/
void fast_blinking(){
    const int LED_SWITCHES = 2;
    int N_ITERATIONS = LED_PROGRAM_DURATION / FAST_BLINKING_DELAY / LED_SWITCHES ;
    Serial.println(N_ITERATIONS);
    for(int i = 0; i < N_ITERATIONS; i++){
        led_on();
        delay(FAST_BLINKING_DELAY);
        led_off();
        delay(FAST_BLINKING_DELAY);
    }
}


/*******************************************************************************
 * @brief   Handling the LED command from the debug handler and calling a led function, depending on the code
 *
 * @param   led_command
 *
 * @return  void
 ******************************************************************************/
void led_error_message(led_state_t led_command) {
    switch(led_command) {
        case LED_ON: no_blinking(); break;
        case LED_BLINK_SLOW: slow_blinking(); break;
        case LED_BLINK_FAST: fast_blinking(); break;
        case LED_OFF: led_off(); break;
        default: /*The debug_handler function only returns one of the above values, 
        thus there is no need for a default case */ 
    }
}

