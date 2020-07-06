 /**
  * This library allows to manage an object "AnalogIn" and/or an object "AnalogOut". Indeed you can read, write, manually set or get the value, without worrying about the normalization 
  *  if the resolutions of the objects are different. Every method has the right controls. 
  * If you want to use this class, initially you will have to create the rispective object "AnalogIn" and/or "AnalogOut", for passing them to the constructor. For more information about this class,
  *  read the descriptions of the methods.
  * Copyright (c) 2020 Davide Palladino. 
  * All right reserved.
  * 
  * @author Davide Palladino
  * @contact davidepalladino@hotmail.com
  * @version 1.1.1
  * @date 6th July, 2020
  * 
  * This library is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU General Public
  *  License as published by the Free Software Foundation; either
  *  version 3.0 of the License, or (at your option) any later version
  * 
  * This library is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  *  GNU Lesser General Public License for more details.
  * 
  */

#ifndef ANALOGCONTROLLER_H
    #define ANALOGCONTROLLER_H

    #include "AnalogIn.h"
    #include "AnalogOut.h"

    class AnalogController {
        public:
            /** 
             * This constructor creates the main object, setting the pointers to the objects where the value will be read and/or write.
             * @param objIn Pointer to object where the value will be read. Set it to "NULL" if will be not used.
             * @param objOut Pointer to object where the value will be written. Set it to "NULL" if will be not used.
             */
            AnalogController(AnalogIn* objIn, AnalogOut* objOut);

            /**
             * This method sets the value. The max value will be considered from "objIn" if exists, and its resolution is not equal to "NONE"; else, the max value will be considered from "objOut".
             *  In example, if you set a resolution of "BIT8" on one of the objects, you can externally set a value between 0 and 255. A value less than 0 will be set to this; greater than 255 will be set to this. Else, if the resolution
             *  is set to "NONE", you can set any value at 32 bit.
             * @param value Value to store.
             */
            void setValue(int32_t value);

            /**
             * This method sets the speed of variation of the value, if the device is an encoder.
             * @param speed Value between "MIN_SPEED" and "MAX_SPEED".
             */
            void setSpeed(uint8_t speed);

            /**
             * This method gets the value.
             * @return Value stored.
             */
            int32_t getValue();

            /**
             * This method gets the max value of "objIn".
             * @return Max value of "objIn" or 0 if "objIn" doesn't exist.
             */
            int32_t getMaxValueIn();

            /**
             * This method gets the max value of "objOut".
             * @return Max value of "objOut" or 0 if "objOut" doesn't exist.
             */
            uint16_t getMaxValueOut();

            /**
             * This method gets the speed of variation of the value, if the device is an encoder.
             * @return Value between "MIN_SPEED" and "MAX_SPEED"; 0 if the device is a potentiometer or "objIn" doesn't exist.
             */
            uint8_t getSpeed();

            /**
             * This method reads and stores the value from a device, with the "objIn".
             */
            void readValue();

            /**
             * This method writes the value stored to a device, with the "objOut".
             * @return The value that was written, or 0 if "ogjOut" doesn't exist.
             * @warning If the value is less than "MIN_VALUE_BIT" or greater of "maxValue" of "objOut", will be normalized.
             */
            uint16_t writeValue();

            /**
             * This method writes a percent of the value stored to a device, with the "objOut".
             * @param percent Percent that will be written to the pin.
             * @return The value that was written, considering the percent. 
             * @warning If the value is less than "MIN_VALUE_BIT" or greater of "maxValue" of "objOut", will be normalized.
             */
            uint16_t writeValue(double percent);

            /**
             * This method activates the blink for "times" in "timeout" milliseconds, with the "objOut". 
             * @param times The number of times.
             * @param timeOut The time from blink to another.
             */
            void blink(uint8_t times, uint32_t timeOut);


        private:
            AnalogIn* objIn;               // Pointer to object where the value will be read. This parameter will be "NULL" if is not set.
            AnalogOut* objOut;             // Pointer to object where the value will be written. This parameter will be "NULL" if is not set.
            int32_t value;                 // Current value read, write or set externally.

            /**
             * This method sets the pointer to object where the value will be read.
             * @param objIn Pointer to object where the value will be read.
             */
            void setObjIn(AnalogIn* objIn);

            /**
             * This method sets the pointer to object where the value will be written.
             * @param objOut Pointer to object where the value will be written.
             */
            void setObjOut(AnalogOut* objOut);

            /**
             * This method gets the pointer to object where the value will be read.
             * @return Pointer to object.
             */
            AnalogIn* getObjIn();

            /**
             * This method gets the pointer to object where the value will be written.
             * @return Pointer to object.
             */
            AnalogOut* getObjOut();            
    };
#endif