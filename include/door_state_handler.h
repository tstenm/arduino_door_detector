#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "hall_sensor.h"

typedef struct
{
    hall_state_t current_value;
    hall_state_t previous_value;
} door_state_t; 

void update_door_state( door_state_t*, hall_state_t);
void init_door_state(door_state_t*, hall_state_t);
bool door_state_altered(door_state_t*);