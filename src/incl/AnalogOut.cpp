#include "AnalogOut.h"

AnalogOut::AnalogOut(uint8_t pin) : AnalogOut(pin, BIT8) {}

AnalogOut::AnalogOut(uint8_t pin, resolution_t resolution) {
    setPin(pin);
    pinMode(getPin(), OUTPUT);

    setResolution(resolution);

    switch (getResolution()) {
        case BIT4:
            setMaxValue(MAX_VALUE_BIT4);
            break;
        case BIT6:
            setMaxValue(MAX_VALUE_BIT6);
            break;
        case BIT8:
        case NONE:
            setMaxValue(MAX_VALUE_BIT8);
            break;
        case BIT10:
            /* Check if the board is DUE, ZERO or MKR family. */
            #if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
                analogWriteResolution((uint8_t) getResolution());
                setMaxValue(MAX_VALUE_BIT10);
            #else
                setResolution(BIT8);
                setMaxValue(MAX_VALUE_BIT8);
            #endif
            break;
        case BIT12:
            /* Check if the board is DUE, ZERO or MKR family. */
            #if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
                analogWriteResolution((uint8_t) getResolution());
                setMaxValue(MAX_VALUE_BIT12);
            #else
                setResolution(BIT8);
                setMaxValue(MAX_VALUE_BIT8);
            #endif
            break;
    }
}

uint16_t AnalogOut::getMaxValue() { return this->maxValue; }

uint16_t AnalogOut::write(uint16_t value) {
    /* Check if the value is greater than "maxValue", by setting it if so. */
    if (value > getMaxValue()) {
        value = getMaxValue();
    }

    /* Normalize the value if the resolution is less than "BIT8". */
    if (getResolution() < BIT8) {
        value = map(value, MIN_VALUE_BIT, getMaxValue(), MIN_VALUE_BIT, MAX_VALUE_BIT8);
    }
    
    analogWrite(getPin(), value);

    return value;
}

void AnalogOut::setPin(uint8_t pin) { this->pin = pin; }

void AnalogOut::setResolution(resolution_t resolution) { this->resolution = resolution; }

void AnalogOut::setMaxValue(uint16_t maxValue) { this-> maxValue = maxValue; }

uint8_t AnalogOut::getPin() { return this->pin; }

resolution_t AnalogOut::getResolution() { return this->resolution; }