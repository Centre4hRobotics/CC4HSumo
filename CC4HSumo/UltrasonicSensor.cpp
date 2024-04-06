#include "UltrasonicSensor.h"


// don't allow multiple reads less than a minimum delta
const unsigned long readTimeDelta = 50;

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin, double maxDistanceInches)
: _ultrasonic(triggerPin, echoPin)
, _lastReadTime(0)
{
    setMaxDistanceInches(maxDistanceInches);
}

double UltrasonicSensor::getDistanceInches() {
    unsigned long time = millis();
    if (time - _lastReadTime < readTimeDelta) {
        return _lastReadDistance;
    }

    double val = _ultrasonic.read() / 2.54;

    if (val > _maxDistance)
        val = _maxDistance;

    _lastReadDistance = val;
    _lastReadTime = time;

    return val;
}

void UltrasonicSensor::setMaxDistanceInches(double distanceInches) {
    _maxDistance = distanceInches;
    _ultrasonic.setTimeout(distanceInches * 74 * 3); // microseconds per inch
}