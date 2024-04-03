#include "DriveMotors.h"
#include <Arduino.h>

// Motor definitions to make life easier:
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1

// Pin Assignments (from ArduMoto shield example)
//Default pins:
#define DIRA 12 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 13 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B

// max speed
const int maxSpeed = 200; // 255 theoretical max, lower it a bit

DriveMotors::DriveMotors() {
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

void DriveMotors::drive(double speed, double steer) {
  double xSpeed = constrain(speed, -1.0, 1.0);
  double zRotation = constrain(steer, -1.0, 1.0);

  double leftMotorOutput;
  double rightMotorOutput;

  double maxInput =
      copysign(fmax(fabs(xSpeed), fabs(zRotation)), xSpeed);

  if (xSpeed >= 0.0) {
    // First quadrant, else second quadrant
    if (zRotation >= 0.0) {
      leftMotorOutput = maxInput;
      rightMotorOutput = xSpeed - zRotation;
    } else {
      leftMotorOutput = xSpeed + zRotation;
      rightMotorOutput = maxInput;
    }
  } else {
    // Third quadrant, else fourth quadrant
    if (zRotation >= 0.0) {
      leftMotorOutput = xSpeed + zRotation;
      rightMotorOutput = maxInput;
    } else {
      leftMotorOutput = maxInput;
      rightMotorOutput = xSpeed - zRotation;
    }
  }

  leftMotorOutput = constrain(leftMotorOutput, -1.0, 1.0);
  rightMotorOutput = constrain(rightMotorOutput, -1.0, 1.0);
  
  setMotorSpeeds(leftMotorOutput, rightMotorOutput);
}

void DriveMotors::stop() {
  setMotorSpeeds(0, 0);
}

void DriveMotors::setMotorSpeeds(double leftSpeed, double rightSpeed) {
  setMotorSpeed(LEFT_MOTOR, -1*leftSpeed);
  setMotorSpeed(RIGHT_MOTOR, rightSpeed);
}

void DriveMotors::setMotorSpeed(int motor, double speed) {
  int directionPin, speedPin;
  if (motor == LEFT_MOTOR) {
    directionPin = DIRA;
    speedPin = PWMA;
  }
  else {
    directionPin = DIRB;
    speedPin = PWMB;
  }

  byte dir = (speed > 0) ? 0 : 1;
  byte spd = maxSpeed * fabs(speed);
  
  digitalWrite(directionPin, dir);
  analogWrite(speedPin, spd);
}