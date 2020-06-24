/**
 Creating the controller object for blinking a led. 
 by Davide Palladino <https://github.com/davidepalladino>
 modified on 21th June, 2020
 by Davide Palladino
*/

#include <AnalogIO.h>

/* Creating the object for writing the value to a device. */
AnalogOut led(9);

/* Creating the controller object. */
AnalogController controllerLed(NULL, &led);

/* Creating the variables to contain the times and the timeout. */
unsigned short times = 3;
unsigned short timeout = 1000;

void setup() {
    Serial.begin(115200);
}

void loop() {
    /* Blinking the device with previous parameters. */
    controllerLed.blink(times, timeout);
}