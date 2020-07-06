#include "AnalogIn.h"

AnalogIn::AnalogIn(uint8_t pin) : AnalogIn (pin, BIT10) {}

AnalogIn::AnalogIn(uint8_t pin, resolution_t resolution) {
    setPinA(pin);

    setDevice(POTENTIOMETER);

    setResolution(resolution);

    switch (getResolution()) {
        case BIT4:
            setMaxValue(MAX_VALUE_BIT4);
            break;
        case BIT6:
            setMaxValue(MAX_VALUE_BIT6);
            break;
        case BIT8:
            setMaxValue(MAX_VALUE_BIT8);
            break;
        case BIT10:
        case NONE:
            setMaxValue(MAX_VALUE_BIT10);
            break;
        case BIT12:
            /* Check if the board is DUE, ZERO or MKR family. */
            #if defined(ARDUINO_ARCH_SAM) || defined(ARDUINO_ARCH_SAMD)
                analogReadResolution((uint8_t) getResolution());
                setMaxValue(MAX_VALUE_BIT12);
            #else
                setResolution(BIT10);
                setMaxValue(MAX_VALUE_BIT10);
            #endif
            break;
    }
}

AnalogIn::AnalogIn(uint8_t pinA, uint8_t pinB) : AnalogIn(pinA, pinB, BIT10) {}

AnalogIn::AnalogIn(uint8_t pinA, uint8_t pinB, resolution_t resolution) {
    setPinA(pinA);
    setPinB(pinB);
    pinMode(getPinA(), INPUT);
    pinMode(getPinB(), INPUT);

    setDevice(ENCODER);

    setResolution(resolution);

    switch (getResolution()) {
        case NONE:
            setMaxValue(VALUE_NONE);
            break;
        case BIT4:
            setMaxValue(MAX_VALUE_BIT4);
            break;
        case BIT6:
            setMaxValue(MAX_VALUE_BIT6);
            break;
        case BIT8:
            setMaxValue(MAX_VALUE_BIT8);
            break;
        case BIT10:
            setMaxValue(MAX_VALUE_BIT10);
            break;
        case BIT12:
            setMaxValue(MAX_VALUE_BIT12);
            break;
    }

    setSpeed(MIN_SPEED);

    setLastStatusEncoder(HIGH);

    setEmulatePinA((bool) !digitalRead(getPinA()));
    setEmulatePinB((bool) !digitalRead(getPinB()));
}

void AnalogIn::setSpeed(uint8_t speed) {
    /* Check if the device is an encoder. In this case, will be set the speed. */
    if (getDevice() == ENCODER) {
        if (speed < MIN_SPEED) {
            this->speed = MIN_SPEED;
        } else if (speed > MAX_SPEED) {
            this->speed = MAX_SPEED;
        } else {
            this->speed = speed;
        }
    }
}

int32_t AnalogIn::getMaxValue() { return this->maxValue; }

uint8_t AnalogIn::getSpeed() { 
    /* Check if the device is an encoder. In this case, will return the speed; else will return 0. */
    if (getDevice() == ENCODER) {
        return this->speed; 
    } else {
        return 0;
    }
}

uint16_t AnalogIn::read() {
    /* Check if the device is a potentiometer. In this case, will be read the value; else will return 0. */
    if (getDevice() == POTENTIOMETER) {
        if (getResolution() < BIT10) {
            return map(analogRead(getPinA()), MIN_VALUE_BIT, MAX_VALUE_BIT10, MIN_VALUE_BIT, getMaxValue());
        } else {
            return analogRead(getPinA());
        }
    } else {
        return 0;
    }
}

int32_t AnalogIn::read(int32_t value) {
    /* Check if the device is an encoder. In this case, will be read the value; else will return 0. */
    if (getDevice() == ENCODER) {
        /* Create a variable to save the last status of the encoder. */
        uint8_t currentStatusEncoder;

        /* Proceed with the first reading of the encoder, checking if the pin emulates or not the digital pin. */
        if (getEmulatePinA()) {
            currentStatusEncoder = analogRead(getPinA()) > 100 ? 1 : 0;
        } else {
            currentStatusEncoder = digitalRead(getPinA());
        }

        /* Proceed with the second reading of the encoder, checking if the pin emulates or not the digital pin. */
        if ((getLastStatusEncoder() == HIGH) && (currentStatusEncoder == LOW)) {
            if (getEmulatePinB()) {
                if (analogRead(getPinB()) > 100 ? 1 : 0) {
                    value += getSpeed();
                } else {
                    value -= getSpeed();
                }
            } else {
                if (digitalRead(getPinB()) == HIGH) {
                    value += getSpeed();
                } else {
                    value -= getSpeed();
                }
            }
        }

        /* If the resolution is not "NONE", the value will be correct if is greater than "maxValue" or less than "MIN_VALUE_BIT" */
        if (getResolution() != NONE) {
            if (value < MIN_VALUE_BIT) {
                value = MIN_VALUE_BIT;
            } else if (value >= getMaxValue()) {
                value = getMaxValue();
            }
        }
       
        /* Save the last status of the encoder with the current, for next reading. */
        setLastStatusEncoder(currentStatusEncoder);

        return value;
    } else {
        return 0;
    }
}

void AnalogIn::setPinA(uint8_t pinA) { this->pinA = pinA; }

void AnalogIn::setPinB(uint8_t pinB) { this->pinB = pinB; }

void AnalogIn::setDevice(device_t device) { this->device = device; }

void AnalogIn::setResolution(resolution_t resolution) { this->resolution = resolution; }

void AnalogIn::setMaxValue(int32_t maxValue) { this-> maxValue = maxValue; }

void AnalogIn::setLastStatusEncoder(uint8_t lastStatusEncoder) { this->lastStatusEncoder = lastStatusEncoder; }

void AnalogIn::setEmulatePinA(bool status) { this->emulatePinA = status; }

void AnalogIn::setEmulatePinB(bool status) { this->emulatePinB = status; }

uint8_t AnalogIn::getPinA() { return this->pinA; }

uint8_t AnalogIn::getPinB() { return this->pinB; }

device_t AnalogIn::getDevice() { return this->device; }

resolution_t AnalogIn::getResolution() { return this->resolution; }

uint8_t AnalogIn::getLastStatusEncoder() { return this->lastStatusEncoder; }

bool AnalogIn::getEmulatePinA() { return this->emulatePinA; }

bool AnalogIn::getEmulatePinB() { return this->emulatePinB; }