#pragma once

/**
 * Class to access a digital reflectance sensor to detect light/dark.
 * The signal pin of the sensor needs to be wired to any one free I/O pin on the JSumo board
 * (see instructions).
 */
class ReflectanceSensor
{
public:
    /**
     * Construct the reflectance sensor on a given pin.
     * 
     * @param pin The pin plugged into the sensor.
     */
    ReflectanceSensor(int pin);

    /**
     * Return the current state of the sensor.
     * 
     * @return Returns true if the sensor is currently sensing dark colors, false otherwise.
     */
    bool isDark();

    /**
     * Return the current state of the sensor.
     * 
     * @return Returns true if the sensor is currently sensing light colors, false otherwise.
     */
    bool isLight();
private:
    int _pin;
};