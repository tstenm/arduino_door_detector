#include <Arduino.h>
#include "hall_sensor.h"





/*******************************************************************************
 * @brief   Sets HALL_PIN in input mode
 *
 * @param   void
 *
 * @return  void
 ******************************************************************************/

void init_hall_pin(){
    pinMode(HALL_PIN, INPUT);
}


bool tmp_hall_sensor()
{
  int hall_effect_sensor_state = digitalRead(HALL_PIN);
  if (hall_effect_sensor_state == LOW) {

    Serial.println("Magnet");
    return true;
  } else {
    Serial.println("njiet Magnet");
    return false;
  } 
}

