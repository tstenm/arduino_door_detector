#ifndef HTTP_H
#define HTTP_H
#include <stdint.h>
#include "hall_sensor.h"


typedef enum {
    HTTP_STATUS_OK = 200,
    HTTP_STATUS_ERROR = -1,
    NO_HTTP_REQUEST = -2,
} http_code_t;





http_code_t http_send_manual_door_status(hall_state_t);
http_code_t decide_http_function(hall_state_t, bool);
#endif

