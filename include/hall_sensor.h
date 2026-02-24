#pragma once
#include <stdbool.h>
#include <stdint.h>

#define HALL_PIN 34



/*Hall-Effect-Sensor gives back 1, when no megnet nearby and 0 when a magnet is nearby*/
typedef enum {
    DOOR_CLOSED = 0,
    DOOR_OPEN = 1,
} hall_state_t;





void init_hall_pin(void);
hall_state_t read_hall_sensor(void);


