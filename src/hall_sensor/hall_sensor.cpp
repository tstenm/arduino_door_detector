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
//tested
hall_state_t read_hall_sensor(){
    if(digitalRead(HALL_PIN)){
        return DOOR_CLOSED;
    }
    else{
        return DOOR_OPEN;
    }
}





/*******************************************************************************
 * @brief   Inits the door_state_t struct with the first value read from the hall effect sensor
 *
 * @param   hall_state_t, door_state_t
 *
 * @return  void
 ******************************************************************************/
// tested
void init_door_state(door_state_t * const door_state,
                     const hall_state_t hall_state)
{
    door_state->current_value  = hall_state;
    door_state->previous_value = hall_state;
}

/*******************************************************************************
 * @brief   Updates the door_state struct after a new value has been read
 *
 * @param   hall_state_t, door_state_t
 *
 * @return  void
 ******************************************************************************/
//tested
void update_door_state(door_state_t * const door_state, const hall_state_t hall_state){
    door_state->previous_value  = door_state->current_value;
    door_state->current_value = hall_state;
}



/*******************************************************************************
 * @brief   Compares both values in door_state_t, to check for updates. 
 *
 * @param   door_state_t
 *
 * @return  true or false
 ******************************************************************************/
//tested 
bool door_state_altered(door_state_t * const door_state){
    return(door_state->current_value != door_state->previous_value);
}