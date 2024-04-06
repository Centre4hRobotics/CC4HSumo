#include "ServoMotor.h"

ServoMotor::ServoMotor(int pin) 
{
    // add sanity checking on pin number!
    _pin = pin;
}

void ServoMotor::initialize()
{
    _servo.attach(_pin);
}

void ServoMotor::setAngle(int angle) 
{
    _servo.write(angle);
}

int ServoMotor::getAngle() 
{
    return _servo.read();
}
