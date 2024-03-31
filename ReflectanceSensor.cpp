#include "ReflectanceSensor.h"
#include <Arduino.h>

ReflectanceSensor::ReflectanceSensor(int pin) {
    _pin = pin;

    pinMode(_pin, INPUT);
}

bool ReflectanceSensor::isLight() {
    return (digitalRead(_pin) == LOW);
}

bool ReflectanceSensor::isDark() {
    return (digitalRead(_pin) == HIGH);
}