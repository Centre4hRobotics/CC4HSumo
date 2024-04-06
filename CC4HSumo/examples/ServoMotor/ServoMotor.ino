#include <CC4HSumo.h>

// Create ServoMotor on port A5. Servo ribbon should
// be connected to ground (black), 5v (red), 11 (yellow)
ServoMotor servo(A5);

void setup() {
  // put your setup code here, to run once:

  // initialize the servo. Needs to be called
  // once in setup() before using the servo.
  servo.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:

  // set servo to 0 position
  servo.setAngle(0);
  // wait a second
  delay(1000);

  // set servo to 90 degrees
  servo.setAngle(90);
  // wait a second
  delay(1000);

  // set servo to 180 degrees
  servo.setAngle(180);
  // wait a second
  delay(1000);

  // will loop back to beginning
}
