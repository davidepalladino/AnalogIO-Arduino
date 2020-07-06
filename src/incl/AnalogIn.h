/**
  * This library allows to read a value from an analog input like an potentiometer, or from a digital input like an encoder.
  * You can specify the device and the resolution of reading.
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

#ifndef ANALOGIN_H
    #define ANALOGIN_H

    #include "globalData.h"

    /**
     * Class for initialize and manage the analog/digital input.
     */
    class AnalogIn {      
        /* Allow the AnalogController class to access a private methods and attributes. */
        friend class AnalogController;   

        public:
            /** 
             * This constructor creates the object setting only the pin, if the device is a potentiometer.
             * @param pin Analog pin where the value will be read, if the device is a potentiometer.
             * @warning The resolution of reading will be 10 bit.
             */
            AnalogIn(uint8_t pin);

            /** 
             * This constructor creates the object setting the pin and the resolution of reading, if the device is a potentiometer.
             * @param pin Analog pin where the value will be read, if the device is a potentiometer.
             * @param resolution Resolution of reading between "BIT4", "BIT6", "BIT8", "BIT10" and "BIT12".
             * @warning Resolution "BIT12" is only for boards DUE, ZERO or MKR family. If you try to set it with a different board, the resolution will be "BIT10".
             *  "NONE" is for encoder's device; if you try to set it, the resolution will be "BIT10."
             */
            AnalogIn(uint8_t pin, resolution_t resolution);

            /** 
             * This constructor creates the object setting only the pins, if the device is an ancoder. Moreover, will be called "pinMode" in "INPUT" mode.
             * @param pinA First digital pin where the value will be read.
             * @param pinB Second digital pin where the value will be read.
             * @warning The resolution of reading will be 10 bit.
             */
            AnalogIn(uint8_t pinA, uint8_t pinB);

            /** 
             * This constructor creates the object setting the pins and the resolution of reading, if the device is an ancoder. Moreover, will be called "pinMode" in "INPUT" mode.
             * @param pinA First digital pin where the value will be read.
             * @param pinB Second digital pin where the value will be read.
             * @param resolution Resolution of reading between "NONE", "BIT4", "BIT6", "BIT8", "BIT10" and "BIT12". 
             *  If you set to "NONE", the min and max value will be that the possible at 32 bit.
             */
            AnalogIn(uint8_t pinA, uint8_t pinB, resolution_t resolution);

            /**
             * This method sets the speed of variation of the value, if the device is an encoder.
             * @param speed Value between "MIN_SPEED" and "MAX_SPEED".
             */
            void setSpeed(uint8_t speed);

            /**
             * This method gets the max value that can be read. 
             * @return Max value that can be read, or the max possible at 32 bit if the resolution is set to "NONE".
             */
            int32_t getMaxValue();

            /**
             * This method gets the speed of variation of the value, if the device is an encoder.
             * @return Value between "MIN_SPEED" and "MAX_SPEED"; 0 if the device is a potentiometer.
             */
            uint8_t getSpeed();

            /**
             * This method reads the value from a potentiometer.
             * @return Value between "MIN_VALUE_BIT" and "maxValue".
             */     
            uint16_t read();

             /**
             * This method reads the value from an encoder. Moreover, there will be the debouncing.
             * @param value Original value to start.
             * @return Value between "MIN_VALUE_BIT" and "maxValue", incremented/decremented according to the speed value. If the resolution is set to "NONE", the min and max value will be that the possible at 32 bit.
             */     
            int32_t read(int32_t value);

        private:
            uint8_t pinA;                       // Pin where the value will be read.
            uint8_t pinB;                       // Pin where the value will be read if the device is an encoder.
            device_t device;                    // Type of device, between "POTENTIOMETER" and "ENCODER".
            resolution_t resolution;            // Type of resolution.
            int32_t maxValue;                   // Max value that can be read.
            uint8_t speed;                      // Speed of variation of the value, if the device is an encoder.
            uint8_t lastStatusEncoder;          // Last status of the encoder, to allow the debouncing.
            bool emulatePinA;                   // Flag to indicate if the "pinA" will be emulated or not.
            bool emulatePinB;                   // Flag to indicate if the "pinB" will be emulated or not.

            /**
             * This method sets the pin of the device.
             * @param pinA Analog pin where the value will be read, if the device is a potentiometer; else, digital pin if the device is an encoder.
             */
            void setPinA(uint8_t pinA);

            /**
             * This method sets the pin of the device if is encoder type.
             * @param pinB Digital pin where the value will be read, if the device is an encoder type.
             */
            void setPinB(uint8_t pinB);

            /**
             * This method sets the type of the device.
             * @param device Value between "POTENTIOMETER" and "ENCODER".
             */
            void setDevice(device_t device);

            /**
             * This method sets the type of the resolution.
             * @param resolution Value between "NONE", "BIT4", "BIT6", "BIT8", "BIT10" and "BIT12".
             */
            void setResolution(resolution_t resolution);

            /**
             * This method sets the max value that can be read.
             * @param maxValue Max value that can be read.
             */
            void setMaxValue(int32_t maxValue);

            /**
             * This method sets the last status of the encoder.
             * @param lastStatusEncoder Value between 0 and 1.
             */                   
            void setLastStatusEncoder(uint8_t lastStatusEncoder);

            /**
             * This method sets if the "pinA" will be emulated or not in digital.
             * @param status Boolean value "true" if the pin will be emulated; "false" if will not be.
             */
            void setEmulatePinA(bool status);

            /**
             * This method sets if the "pinB" will be emulated or not in digital.
             * @param status Boolean value "true" if the pin will be emulated; "false" if will not be.
             */
            void setEmulatePinB(bool status);

            /**
             * This method gets the "pinA".
             * @return Analog pin if the device is a potentiometer; else, digital pin if the device is an encoder.
             */         
            uint8_t getPinA();

            /**
             * This method gets the "pinB".
             * @return Digital pin if the device is an encoder.
             */        
            uint8_t getPinB();

            /**
             * This method gets the type of the device.
             * @return Value between "POTENTIOMETER" and "ENCODER".
             */    
            device_t getDevice();

            /**
             * This method gets the type of the resolution.
             * @return Value between "NONE", "BIT4", "BIT6", "BIT8", "BIT10" and "BIT12".
             */    
            resolution_t getResolution();

            /**
             * This method gets the last status of the encoder.
             * @return Value between 0 and 1.
             */  
            uint8_t getLastStatusEncoder();

            /**
             * This method gets if the "pinA" will be emulated or not in digital.
             * @return Boolean value "true" if the pin will be emulated; "false" if will not be.
             */ 
            bool getEmulatePinA();

            /**
             * This method gets if the "pinB" will be emulated or not in digital.
             * @return Boolean value "true" if the pin will be emulated; "false" if will not be.
             */ 
            bool getEmulatePinB(); 
    };
#endif