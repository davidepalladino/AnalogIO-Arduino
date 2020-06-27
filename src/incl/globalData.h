#pragma once

#ifndef ARDUINO_H
        #include <Arduino.h>                    // Import the Arduino library.
#endif

#define MIN_SPEED 1
#define MAX_SPEED 16

#define VALUE_NONE 0
#define MIN_VALUE_BIT 0
#define MAX_VALUE_BIT4 15
#define MAX_VALUE_BIT6 64
#define MAX_VALUE_BIT8 255
#define MAX_VALUE_BIT10 1023
#define MAX_VALUE_BIT12 4095

typedef enum resolution : uint8_t {
    NONE,
    BIT4 = 4,
    BIT6 = 6,
    BIT8 = 8,
    BIT10 = 10,
    BIT12 = 12
} resolution_t;

typedef enum device : uint8_t {POTENTIOMETER, ENCODER} device_t;
