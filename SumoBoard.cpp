#include "SumoBoard.h"

#include <Arduino.h>


// the pin for the start button
const int startButtonPin = 10;
const int led1Pin = 8;
const int led2Pin = 9;

SumoBoard::SumoBoard() {
    pinMode(startButtonPin, INPUT);
    pinMode(led1Pin, OUTPUT);
    pinMode(led2Pin, OUTPUT);
}

void SumoBoard::waitForStartButton() {
    while(!isStartButtonPressed()) {
        delay(20);
    }
}

bool SumoBoard::isStartButtonPressed() {
    return (digitalRead(startButtonPin) == HIGH);
}

void SumoBoard::setLed1(bool on) {
    digitalWrite(led1Pin, on ? HIGH : LOW);
}

void SumoBoard::setLed2(bool on) {
    digitalWrite(led2Pin, on ? HIGH : LOW);
}

