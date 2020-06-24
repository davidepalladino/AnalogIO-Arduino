/**
  * This library allows to write a value on digital output, exactly on PWM pin. 
  * You can specify the resolution of writing.
  * Copyright (c) 2020 Davide Palladino. 
  * All right reserved.
  * 
  * @author Davide Palladino
  * @contact davidepalladino@hotmail.com
  * @version 1.0
  * @date 21th June, 2020
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

#ifndef ANALOGOUT_H
    #define ANALOGOUT_H
    
    #include "globalData.h"

    /**
     * Class for initialize and manage the analog output.
     */
    class AnalogOut {
        /* Allow the AnalogController class to access a private methods and attributes. */
        friend class AnalogController;

        public:
            /** 
             * This constructor creates the object setting only the pin of writing. 
             * @param pin Digital pin where the value will be written.
             * @warning The resolution of writing will be "BIT8".
             */
            AnalogOut(uint8_t pin);

            /** 
             * This constructor creates the object setting the pin and the resolution of writing. 
             * @param pin Digital pin where the value will be written.
             * @param resolution Resolution of writing between "BIT4", "BIT6", "BIT8", "BIT10" and "BIT12".
             * @warning The resolutions "BIT10" and "BIT12" is only for boards DUE, ZERO or MKR family. If you try to set it with a different board, the resolution will be "BIT8".
             */
            AnalogOut(uint8_t pin, resolution_t);

            /**
             * This method gets the max value that can be written.
             * @return Max value that can be written.
             */
            uint16_t getMaxValue();

            /**
             * This method writes the value to the pin.
             * @param value Value to write, between "MIN_VALUE_BIT" and "maxValue".
             * @return Value written.
             */     
            uint16_t write(uint16_t value);

        private:
            uint8_t pin;                        // Pin where the value will be written. 
            resolution_t resolution;            // Type of resolution.
            uint16_t maxValue;                  // Max value that can be written.

            /**
             * This method sets the pin where the value will be written.
             * @param pin Digital pin where the value will be written.
             */
            void setPin(uint8_t pin);

            /**
             * This method sets the type of the resolution.
             * @param resolution Value between "BIT8", "BIT10" and "BIT12".
             */
            void setResolution(resolution_t resolution);

            /**
             * This method sets the max value that can be written.
             * @param maxValue Max value that can be written.
             */
            void setMaxValue(uint16_t maxValue);

            /**
             * This method gets the pin where the value will be written. 
             * @return Digital pin where the value will be written. 
             */         
            uint8_t getPin();

            /**
             * This method gets the type of the resolution.
             * @return Value between "BIT8", "BIT10" and "BIT12".
             */    
            resolution_t getResolution();
    };
#endif