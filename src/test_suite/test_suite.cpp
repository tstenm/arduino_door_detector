#include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>
#include "wifi.h"
#include "test_suite.h"
#include "hall_sensor.h"
#include "door_state_handler.h"
#include "http.h"

/*******************************************************************************
 * @brief   Tests the system. Be aware to set the definitions correctly. Be aware, that some tests can also fail because of external
 * conditions, like a broken WiFi router, a broken hall-effect sensor etc. 
 * first if clauses test wifi. second tests hall-effect-sensor. third tests http. Last tests led. Multiple things have to work and more fine grained testing is maybe required
 * to identify the source of the problem, if the code is correct. Prints out over the serial monitor, if everything works fine.
 * This test-suite is not really good, because of time management problems
 * @param   void
 *
 * @return void
 ******************************************************************************/

void run_tests(){

    bool tests_succesful = true;
    if(WIFI_WRONG_AUTHENTIFICATION){
        wifi_code_t wifi_status = wifi_init();
        if(wifi_status == WIFI_STATUS_OK){
            tests_succesful = false;
            Serial.println("Wifi test failed");
        }
        else{
            tests_succesful = tests_succesful;
        }
    }
    else{
        wifi_code_t wifi_status = wifi_init();
        if(wifi_status == WIFI_STATUS_OK){
            tests_succesful = tests_succesful;
        }
        else{
            tests_succesful = false;
            Serial.println("Wifi test failed");
        }
    }
    if(MAGNET_PRESENT){
        hall_state_t hall_state = read_hall_sensor();
        if(hall_state == DOOR_OPEN){
            tests_succesful = false;
            Serial.println("Hall-Sensor test failed");
        }

    }
    else{
        hall_state_t hall_state = read_hall_sensor();
        if(hall_state == DOOR_CLOSED){
            tests_succesful = false;
            Serial.println("Hall-Sensor test failed");
        }
        else{
            tests_succesful = tests_succesful;
        }
    }
    door_state_t door_state;
    init_door_state(&door_state, DOOR_OPEN);
    if(door_state_altered(&door_state)){
        tests_succesful =false;
        Serial.println("Door state handler test failed: init_door_state");
    }
    else{
        tests_succesful = tests_succesful;
    }
    update_door_state(&door_state, DOOR_CLOSED);
    if(door_state.current_value != DOOR_CLOSED){
        tests_succesful = false;
        Serial.println("Door state handler test failed: update_door_state");
    }

    http_code_t http_code;
    bool door_status_changed = false;
    http_code = decide_http_function(DOOR_CLOSED, door_status_changed);
  if(http_code != NO_HTTP_REQUEST){
    tests_succesful = false;
    Serial.println("http failed : decide_http_function");
  }
    else{
    door_status_changed = true;
    http_code = decide_http_function(DOOR_OPEN, door_status_changed);
    if(http_code != HTTP_STATUS_OK){
        tests_succesful = false;
        Serial.println("Making the http request failed. First check the backend, before further inspection.");
    }
    else{
        // tests_succesful stays unaltered, thus not action is needed
    }
}
    
    if(tests_succesful){
        Serial.println("Tests succesful and everything should work fine");
    }
    else{
        Serial.println("Tests failed. Further inspection required.");
    }

    }
