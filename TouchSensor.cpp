#include "TouchSensor.h"
#include <Arduino.h>

TouchSensor::TouchSensor(int pin) {
    _pin = pin;

    pinMode(_pin, INPUT_PULLUP);
}

bool TouchSensor::isTouched() {
    return (digitalRead(_pin) == LOW);
}