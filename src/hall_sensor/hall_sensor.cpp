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
/*******************************************************************************
 * @brief   Reads out hall effect pin. digitalRead(HALL_PIN) returns 1, when there is no magnet nearby and 0 otherwise
 *
 * @param   /
 *
 * @return  DOOR_OPEN or DOOR_CLOSED
 ******************************************************************************/

hall_state_t read_hall_sensor(){
    uint8_t hall_value = digitalRead(HALL_PIN);
    if(hall_value){
        return DOOR_CLOSED;
    }
    else{
        return DOOR_OPEN;
    }
}





