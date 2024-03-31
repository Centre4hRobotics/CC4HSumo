#include <CC4HSumo.h>

// create the reflectance sensor on pin 4
// sensor should be plugged into ground (GND), 5v (VIN), and 4 (D0)
ReflectanceSensor reflect(4);

// also use the SumoBoard to turn on a LED
SumoBoard board;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

  if (reflect.isLight()) 
    board.setLed1(true);
  else
    board.setLed2(false);
}
