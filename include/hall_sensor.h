#include <stdbool.h>
#include <stdint.h>

#define HALL_PIN 34


typedef struct
{
    uint8_t current_value;
    uint8_t previous_value;
} hall_state_t;


void init_hall_pin(void);

hall_state_t get_current_value(void);


