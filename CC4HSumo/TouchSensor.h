#pragma once

/**
 * Class to access a touch sensor, meaning any kind of normally open switch.
 * The sensor needs to be wired into GROUND and any one free I/O pin on the JSumo Board
 * (see instructions).
 */
class TouchSensor 
{
public:
    /**
     * Construct the touch sensor on a given pin.
     * 
     * @param pin The pin plugged into the sensor.
     */
    TouchSensor(int pin);

    /**
     * Return the current state of the sensor.
     * 
     * @return Returns true if the switch is currently closed, false if its open.
     */
    bool isTouched();
private:
    int _pin;
};