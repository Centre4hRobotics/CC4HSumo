#include <CC4HSumo.h>

// Declare the DriveMotors object so we can use it below
DriveMotors motors;

// drive forward, turn, drive forward, stop
void setup() {
  // wait 5 seconds to back up after powering on
  delay(5000);

  // drive straight at 50% speed
  motors.drive(0.5, 0.0);
  // keep driving for 1 second (1000 ms)
  delay(1000);

  // turn right at 25% power
  motors.drive(0.0, 0.25);
  // keep turning for 1 second
  delay(1000);

  // drive straight at 50% speed
  motors.drive(0.5, 0.0);
  // keep driving for 1 second (1000 ms)
  delay(1000);

  // stop
  motors.stop();
}

// don't do anything in loop
void loop() {}
