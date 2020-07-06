#include "AnalogController.h"

AnalogController::AnalogController(AnalogIn* objIn, AnalogOut* objOut){
    setObjIn(objIn);
    setObjOut(objOut);

    setValue(MIN_VALUE_BIT);
}

void AnalogController::setValue(int32_t value) {
    /* Check if the "objIn" exists, and in this case will be considered the "MIN_VALUE_BIT" and the "maxValue" if the resolution is not equal to "NONE". */
    if (getObjIn() != NULL) {
        if (getObjIn()->getResolution() != NONE) {
            if (value < MIN_VALUE_BIT) {
                this->value = MIN_VALUE_BIT;
            } else if (value > getMaxValueIn()) {
                this->value = getMaxValueIn();
            } else {
                this->value = value;
            }
        } else {
            this->value = value;
        }
    /* If the "objIn" doesn't exist, will be considered the "objOut". */
    } else if ((getObjIn() == NULL) && (getObjOut() != NULL)) {
        if (value < MIN_VALUE_BIT) {
            this->value = MIN_VALUE_BIT;
        } else if (value > getMaxValueOut()) {
            this->value = getMaxValueOut();
        } else {
            this->value = value;
        }
    }
}

void AnalogController::setSpeed(uint8_t speed) {
    if (getObjIn() != NULL) {
        getObjIn()->setSpeed(speed);
    }
}

int32_t AnalogController::getValue() { return this->value; }

void AnalogController::readValue() {
    if (getObjIn() != NULL) {
        /* Check the device, to execute the correct method. */
        if (getObjIn()->getDevice() == POTENTIOMETER) {
            setValue(getObjIn()->read());
        } else if (getObjIn()->getDevice() == ENCODER) {
            setValue(getObjIn()->read(getValue()));
        }
    }
}


int32_t AnalogController::getMaxValueIn() {
    if (getObjIn() != NULL) {
        return getObjIn()->getMaxValue();
    } else {
        return 0;
    }
}

uint16_t AnalogController::getMaxValueOut() {
    if (getObjOut() != NULL) {
        return getObjOut()->getMaxValue();
    } else {
        return 0;
    }
}

uint8_t AnalogController::getSpeed() {
    if (getObjIn() != NULL) {
        return getObjIn()->getSpeed();
    } else {
        return 0;
    }
}

uint16_t AnalogController::writeValue() {
    return writeValue(100);
}

uint16_t AnalogController::writeValue(double percent) {
    if (getObjOut() != NULL) {
        int32_t valueTemp = getValue();

        /* Normalize the value if the resolution is not similar between "objIn" and "objOut". */
        if ((getObjIn() != NULL) && (getObjIn()->getResolution() != NONE) && (getObjIn()->getResolution() != getObjOut()->getResolution())) {
            valueTemp = map((uint16_t) valueTemp, MIN_VALUE_BIT, getMaxValueIn(), MIN_VALUE_BIT, getMaxValueOut());
        /* Force the value to "MIN_VALUE_BIT" or "maxValue" of "objOut" if the value is greater or less than them, and the resolution of "objIn" is set to "NONE". */
        } else if ((getObjIn() != NULL) && (getObjIn()->getResolution() == NONE)) {
            if (valueTemp < MIN_VALUE_BIT) {
                valueTemp = MIN_VALUE_BIT;
            } else if (valueTemp > getMaxValueOut()) {
                valueTemp = getMaxValueOut();
            }
        }
        
        /* Calculate the percent, if is less than 100. */
        if (percent != 100) {
            valueTemp = ((double) valueTemp * percent) / 100;
        }

        return getObjOut()->write((uint16_t) valueTemp);
    } else {
        return 0;
    }
}

void AnalogController::blink(uint8_t times, uint32_t timeOut) {
    if (getObjOut() != NULL) {
        for (uint8_t t = 1; t <= times; t++) {
            getObjOut()->write(getMaxValueOut());
            delay(timeOut);
            getObjOut()->write(MIN_VALUE_BIT);

            if(t < times) {
                delay(timeOut);
            }
        }    
    }
}

void AnalogController::setObjIn(AnalogIn* objIn) {
    this->objIn = objIn;
}

void AnalogController::setObjOut(AnalogOut* objOut) {
    this->objOut = objOut;
}

AnalogIn* AnalogController::getObjIn() {
    return this->objIn;
}

AnalogOut* AnalogController::getObjOut() {
    return this->objOut;
}