#include "AnalogReflectanceSensor.h"
#include <Arduino.h>

AnalogReflectanceSensor::AnalogReflectanceSensor(int pin) {
    _pin = pin;
}

double AnalogReflectanceSensor::getReflectance() {
    return analogRead(_pin) / 1023.0;
}
