////////////////////////////////////////
// Arduino Code for F 894
////////////////////////////////////////

#include "globals2.h"

void setup() {
  /////
  // Set up pins
  pinMode(upPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(selectPin, INPUT_PULLUP);
  pinMode(yellowPin, OUTPUT);

  ////
  // Start LCD
  lcd.begin(20,4);
  WelcomeScreen();
  delay(1000*5);
  displayMenu();
}

void loop() {
  handleButtons();
}