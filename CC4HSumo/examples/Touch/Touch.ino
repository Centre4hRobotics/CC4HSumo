#include <CC4HSumo.h>

// Create TouchSensor using pin A4.
// Sensor wires should be connected to GROUND and A4
TouchSensor touch(A4);

// use SumoBoard too so we can turn on light
SumoBoard board;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read the touch sensor
  bool isTouched = touch.isTouched();

  // turn red LED on if button is pressed.
  if (isTouched)
    board.setLed1(true);
  else
    board.setLed1(false);
}
