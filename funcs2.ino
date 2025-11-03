#include "globals2.h"

////
// Function to print the welcome screen
void WelcomeScreen() {
  lcd.clear();

  lcd.print("Welcome to the:");
  lcd.setCursor(0,1);
  lcd.print("Schizophrenia Menu!");
  lcd.setCursor(0,2);
  lcd.print("v0.0.0.0.1");
  lcd.setCursor(0,3);
  lcd.print("by: Luscao");
}

////
// Function to manage the main menu screen

void displayMenu() {
  int startIdx = 0;
  int numoptions = menulist[menuState].itemCount;

  lcd.clear();

  // Check which option will be printed in the first line of the LCD
  if (cursor > 3) {
    startIdx = cursor - 3;
  }
  // Don't allow infinite scrolling
  if (startIdx > numoptions - 4) {
    startIdx = numoptions - 4;
  }
  // Just a fix in case there are less then 4 options
  if (startIdx < 0) { 
    startIdx = 0;
  }

  // Now start printing the menu
  for (int i=0; i<4; i++) {
    if (startIdx + i < numoptions) {
      lcd.setCursor(0,i);
      lcd.print(cursor == startIdx + i ? ">" : " ");
      lcd.print(menulist[menuState].options[startIdx + i]);
    }
  }
}

void handleButtons() {
  static unsigned long lastButtonPress = 0;
  unsigned long currentTime = millis();

  // Debounce delay of 200ms
  if (currentTime - lastButtonPress < 200) {
    return;
  }

  if (digitalRead(upPin) == LOW) {
    cursor--;
    if (cursor < 0) {
      cursor = 0;
    }
    displayMenu();
    lastButtonPress = currentTime;
  }

  if (digitalRead(downPin) == LOW) {
    cursor++;
    if (cursor > menulist[menuState].itemCount - 1) {
      cursor--;
    }
    displayMenu();
    lastButtonPress = currentTime;
  }

  if (digitalRead(selectPin) == LOW) {
    handleSelect();
    displayMenu();
    lastButtonPress = currentTime;
  }
}

void handleSelect() {
  menulist[menuState].actions[cursor]();
}

