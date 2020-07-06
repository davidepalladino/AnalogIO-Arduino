In this document there is the story about the various versions. See the [Wiki](https://github.com/davidepalladino/AnalogIO-Arduino/wiki) page for detail about the use.

### 1.1.1 - 2020-07-06
**Added**
* Now you can get the max value of the object `AnalogIn` from the object `AnalogController`.
* Now you can get the max value of the object `AnalogOut` from the object `AnalogController`.

**Changed**
* Value of `VALUE_NONE` from `0` to the max value of 32 bit.
* Return type of `getMaxValue`, for `AnalogIn`, from `uint16_t` to `int32_t`.
* Parameter type of `timeOut`, for `AnalogController`, from `uint8_t` to `uint32_t`.

**Fixed**
* Bug related to emulation of analog pins.