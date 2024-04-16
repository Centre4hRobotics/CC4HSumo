#include <CC4HSumo.h>

// create the reflectance sensor on analog pin A1
// sensor should be plugged into ground (GND), 5v (VIN), and A1 (A)
AnalogReflectanceSensor reflect(A1);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:

  // print the value to the terminal
  Serial.print("Reflectance: ");
  Serial.println(reflect.getReflectance());

  // wait a second
  delay(1000);
}
