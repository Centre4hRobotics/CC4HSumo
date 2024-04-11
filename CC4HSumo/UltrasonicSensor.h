#pragma once

#include <Arduino.h>
#include <Ultrasonic.h>

/**
 * Class to access a HC-SR04 Ultrasonic Sensor, used for distance detection.
 * The sensor needs to be wired into two free I/O pins on the JSumo (see instructions
 * for a list of available pins.)
 */
class UltrasonicSensor 
{
public:
    /**
     * Construct the UltrasonicSensor with given pins and an optional maximum read distance.
     * 
     * @param triggerPin The pin connected to TRIG on the sensor.
     * @param echoPin The pin connected to ECHO on the sensor.
     * @param maxDistanceInches The maximum read distance for the sensor (inches). Defaults to 24.0 inches.
     */
    UltrasonicSensor(int triggerPin, int echoPin, double maxDistanceInches = 24.0);

    /**
     * Set the maximum distance that the sensor should read. A lower value will read a bit quicker.
     * @param maxDistanceInches The maximum read distance for the sensor (inches).
     */
    void setMaxDistanceInches(double maxDistanceInches);

    /**
     * Get the distance from the sensor to the nearest solid object in inches. Note that this
     * method will delay for a bit while the ultrasonic signal is sent and received. For the default
     * max distance of 24 inches the delay will be about 4 milliseconds.
     * 
     * @return The distance to the nearest solid object in inches. If no such object is found within
     *  the current max distance, the max distance will be returned.
     */
    double getDistanceInches();
private:
    Ultrasonic _ultrasonic;
    double _maxDistance;
    unsigned long _lastReadTime;
    double _lastReadDistance;
};