/**
 Writing the value to digital output.
 by Davide Palladino <https://github.com/davidepalladino>
 modified on 21th June, 2020
 by Davide Palladino
*/

#include <AnalogIO.h>

/* Creating the object for writing the value to a device. */
AnalogOut led(9, BIT6);

/* Creating the variable to contain the value to write. */
unsigned short valueWrite = 50;

/* Creating the variable to contain the value written. */
unsigned short valueWritten;

void setup() {
    Serial.begin(9600);

    /* Writing on Serial Monitor the value to write . */
    Serial.print("It was sent a BIT6 value ");
    Serial.print(valueWrite);

    /* Sending the value to the device and storing the value written. */
    valueWritten = led.write(valueWrite);

    /* Writing on Serial Monitor the value written. */
    Serial.print(" but was been normalized and written ");
    Serial.println(valueWritten);
}

void loop() {

}
