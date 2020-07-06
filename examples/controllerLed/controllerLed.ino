/**
 Creating the controller object for reading and writing a value. 
 by Davide Palladino <https://github.com/davidepalladino>
 modified on 21th June, 2020
 by Davide Palladino
*/

#include <AnalogIO.h>

/* Creating the object for reading the value from an encoder. */
AnalogIn encoder(A0, A1, BIT6);

/* Creating the object for writing the value to a device. */
AnalogOut led(9);

/* Creating the controller object. */
AnalogController controllerLed(&encoder, &led);

void setup() {
    Serial.begin(57600);
}

void loop() {
    /* Reading and writing the values from and to the device, and writing the results on Serial Monitor. */
    controllerLed.readValue();

    Serial.print("Value read: ");
    Serial.print(controllerLed.getValue());

    Serial.print(" - value written: ");
    Serial.println(controllerLed.writeValue());
}
