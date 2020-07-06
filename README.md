# AnalogIO library for Arduino
## Description
This library allows to read a value from an analog input like an potentiometer, or from a digital input like an encoder. Moreover, allows to write it on digital output, exactly on PWM pin. You can specify the device, and the resolution of reading and writing. If you want, there is a controller class that manages an object AnalogIn and/or an object AnalogOut, without worrying about the normalization if the resolutions of the objects are different.

## Manual installation
To install manually this library, you can see this little guides.

### Arduino IDE
1. Download and extract it
2. Open Arudino IDE
3. Select tab `Sketch` -> `Include Library` -> `Add .ZIP Library`
4. Select the zip file included in `extras`
You can select the library on `Include Library` -> `AnalogIO`. It will be automatically added on you project, like this:
```c++
#include <AnalogIO.h>
```

### Other IDE
1. Download and extract it
2. Copy the `src` content in your project folder
3. Open the project with your IDE
4. Use the preprocessor directives to add the library, like this:
```c++
#include "AnalogIO.h"
```
## How to use
See the [Wiki](https://github.com/davidepalladino/AnalogIO-Arduino/wiki) page for details about the use.

## Changelog
See the [Changelog](/CHANGELOG.md) page for details about the versions.

## Contribute
Your contribute is important for me. Don't hesitate with issues and pull requests for improving this class.

### Special thanks
Special thanks to my cousin [Marco Palladino](https://github.com/PalladinoMarco) for the help to optimize the code.
