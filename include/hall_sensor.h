#ifndef HALL_SENSOR_H
#define HALL_SENSOR_H

#define HALL_PIN 34


typedef enum {
    DOOR_CLOSED = 0,
    DOOR_OPEN = 1,
} hall_state_t;

void init_hall_pin(void);
hall_state_t read_hall_sensor(void);


#endif