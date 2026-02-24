#include <Arduino.h>
#include "hall_sensor.h"





/*******************************************************************************
 * @brief   Sets HALL_PIN in input mode
 *
 * @param   void
 *
 * @return  void
 ******************************************************************************/
//tested
void init_hall_pin(){
    pinMode(HALL_PIN, INPUT);
}
/*******************************************************************************
 * @brief   Reads out hall effect pin
 *
 * @param   /
 *
 * @return  DOOR_OPEN or DOOR_CLOSED
 ******************************************************************************/

hall_state_t read_hall_sensor(){
    if(digitalRead(HALL_PIN)){
        return DOOR_CLOSED;
    }
    else{
        return DOOR_OPEN;
    }
}





