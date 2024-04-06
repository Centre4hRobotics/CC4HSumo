#include <CC4HSumo.h>

// Declare the SumoBoard and DriveMotors objects so we can use them below
SumoBoard board;
DriveMotors motors;

// drive forward, turn, drive forward, stop
void setup() {
  // wait for the START button on the sumo board to be pressed
  board.waitForStartButton();

  // wait 5 seconds to start driving
  delay(5000);

  // drive straight at 50% speed
  motors.drive(0.5, 0.0);
  // keep driving for 1 second (1000 ms)
  delay(1000);

  // turn right at 50% power
  motors.drive(0.0, 0.5);
  // keep turning for 0.5 seconds (500 ms)
  delay(500);

  // drive straight at 50% speed
  motors.drive(0.5, 0.0);
  // keep driving for 1 second (1000 ms)
  delay(1000);

  // stop
  motors.stop();
}

// don't do anything in loop
void loop() {}
