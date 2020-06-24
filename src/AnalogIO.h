 /**
  * This library allows to read a value from an analog input like an potentiometer, or from a digital input like an encoder. Moreover, allows to write it on digital output, exactly on PWM pin. 
  * You can specify the device, and the resolution of reading and writing. If you want, there is a controller class that manages an object "AnalogIn" and/or an object "AnalogOut", 
  *  without worrying about the normalization if the resolutions of the objects are different.
  * If you want more information about the classes, you can read the respective file header or the Wiki page on GitHub.
  * Copyright (c) 2020 Davide Palladino. 
  * All right reserved.
  * 
  * @author Davide Palladino
  * @contact davidepalladino@hotmail.com
  * @version 1.0
  * @date June 21th, 2020
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

#include "incl/AnalogController.h"
#include "incl/AnalogIn.h"
#include "incl/AnalogOut.h"