#pragma once

/**
 * Class to access an analog reflectance sensor to detect light/dark.
 * The signal pin of the sensor needs to be wired to one of the ANALOG ports of the JSumo board.
 * (see instructions).
 */
class AnalogReflectanceSensor
{
public:
    /**
     * Construct the reflectance sensor on a given pin.
     * 
     * @param pin The ANALOG pin plugged into the sensor.
     */
    AnalogReflectanceSensor(int pin);

    /**
     * Return the sensor value
     */
    double getReflectance();
private:
    int _pin;
};