/**
 Reading the value from an encoder with a different speed.
 by Davide Palladino <https://github.com/davidepalladino>
 modified on 21th June, 2020
 by Davide Palladino
*/

#include <AnalogIO.h>

/* Creating the object for reading the value from an encoder with "BIT8" of resolution. */
AnalogIn encoder(4, 5, BIT8);

/* Creating the variable to contain the value read. */
unsigned short valueEncoder = 0;

void setup() {
    Serial.begin(115200);
  
    /* Changing the speed of reading. */
    encoder.setSpeed(5);
}

void loop() {
    /* Reading of the value from the device, and write them on Serial Monitor. */
    valueEncoder = encoder.read(valueEncoder);
    Serial.print("Value read: ");
    Serial.println(valueEncoder);
}