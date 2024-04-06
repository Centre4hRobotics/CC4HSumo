#pragma once

#include <Servo.h>

/**
 * Class to access a servo motor. See instructions for how to connect to your JSumo board.
 */
class ServoMotor
{
public:
    /**
     * Construct the ServoMotor with a given pin. 
     * 
     * Make sure you call initialize() in your setup function to enable the servo.
     * @param pin The pin the servo is connected to.
     */
    ServoMotor(int pin);

    /**
     * Initialize the ServoMotor. Must be called before the servo is used.
     */
    void initialize();

    /**
     * Set the angle of the servo.
     * @param angle The angle (between 0 and 180) that you want to set the servo to.
     */
    void setAngle(int angle);

    /**
     * Return the last set angle of the servo.
     * @return The angle (between 0 and 180) of the servo.
     */
    int getAngle();
private:
    Servo _servo;
    int _pin;
};