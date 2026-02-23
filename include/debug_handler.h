#pragma once
#ifndef _DEBUG_HANDLER_H
#define _DEBUG_HANDLER_H

#include "wifi.h"
#include "http.h" 
#include "led.h"

led_state_t wifi_debug_handler(wifi_code_t);
led_state_t http_debug_handler(wifi_code_t, http_code_t); 

#endif


