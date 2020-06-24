/**
 Creating the controller object for reading and writing a percent of value.
 by Davide Palladino <https://github.com/davidepalladino>
 modified on 21th June, 2020
 by Davide Palladino
*/

#include <AnalogIO.h>

/* Creating the object for reading the value from an encoder. */
AnalogIn encoder(4, 5, BIT6);

/* Creating the object for writing the value to a device. */
AnalogOut led(9);

/* Creating the controller object. */
AnalogController controllerLed(&encoder, &led);

void setup() {
    Serial.begin(115200);
}

void loop() {
    /* Reading and writing the values from and to the device, and writing the results on Serial Monitor. */
    controllerLed.readValue();

    Serial.print("Value read: ");
    Serial.print(controllerLed.getValue());

    Serial.print(" - value written: ");
    Serial.println(controllerLed.writeValue(50));       // Will be written the 50% of the value.
}
