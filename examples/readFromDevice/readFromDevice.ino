/**
 Reading the values from to different device.
 by Davide Palladino <https://github.com/davidepalladino>
 modified on 21th June, 2020
 by Davide Palladino
*/

#include <AnalogIO.h>

/* Creating the object for reading the value from a potentiometer. */
AnalogIn potentiometer(A0, BIT8);

/* Creating the object for reading the value from an encoder with "BIT8" of resolution. */
AnalogIn encoderBIT8(2, 3, BIT8);

/* Creating the object for reading the value from an encoder with "NONE" of resolution. */
AnalogIn encoderNONE(4, 5, NONE);

/* Creating the variables to contain the values read. */
unsigned short valuePotentiometer = 0;
unsigned short valueEncoderBIT8 = 0;
int valueEncoderNONE = 0;

void setup() {
    Serial.begin(115200);
}

void loop() {
    /* Reading of the values from the devices, and write them on Serial Monitor. */
    valuePotentiometer = potentiometer.read();
    Serial.print("potentiometer: ");
    Serial.print(valuePotentiometer);

    valueEncoderBIT8 = encoderBIT8.read(valueEncoderBIT8);
    Serial.print(" - encoderBIT8: ");
    Serial.print(valueEncoderBIT8);

    valueEncoderNONE = encoderNONE.read(valueEncoderNONE);
    Serial.print(" - encoderNONE: ");
    Serial.println(valueEncoderNONE);
}
