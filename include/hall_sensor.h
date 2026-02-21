#include <stdbool.h>
#include <stdint.h>

#define HALL_PIN 34



/*Hall-Effect-Sensor gives back 1, when no megnet nearby and 0 when a magnet is nearby*/
typedef enum {
    DOOR_OPEN = 0,
    DOOR_CLOSED = 1,
} hall_state_t;

typedef struct
{
    hall_state_t current_value;
    hall_state_t previous_value;
} door_state_t; 



void init_hall_pin(void);
hall_state_t read_hall_sensor(void);
void update_door_state( door_state_t*, hall_state_t);
void init_door_state(door_state_t*, hall_state_t);
bool door_state_altered(door_state_t*);

