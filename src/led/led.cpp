#include <Arduino.h>
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
 * @param   vodi
 *
 * @return  void
 ******************************************************************************/
void led_off(){
    digitalWrite(LED_PIN, LOW);
}




/*******************************************************************************
 * @brief   Lets LED blink slow for .. seconds
 *
 * @param   vodi
 *
 * @return  void
 ******************************************************************************/
void slow_blinking(){
    for(int i = 0; i < 5; i++){
        led_on();
        delay(SLOW_BLINKING_DELAY);
        led_off();
        delay(SLOW_BLINKING_DELAY);
    }
}
/*******************************************************************************
 * @brief   Lets LED blink fast for .. seconds
 *
 * @param   vodi
 *
 * @return  void
 ******************************************************************************/
void fast_blinking(){
    for(int i = 0; i < 10; i++){
        led_on();
        delay(500);
        led_off();
        delay(500);
    }

}
