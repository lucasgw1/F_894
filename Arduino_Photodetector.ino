////////////////////////////////////////
// Arduino Code F 894
////////////////////////////////////////

#include <LiquidCrystal.h>

// LCD Variables
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Photodetector Variables
const int PhotoPin = A1; 
int PhotoValue = 0; 
float voltage = 0.0;  

void setup() {
  // Set up photodetector
  pinMode(PhotoPin, INPUT);

  // Set up LCD
  lcd.begin(16,2); // Number of columns and rows
  lcd.print("Voltage:");
}

void loop() {
  // Read photodetector value and convert to analog voltage
  PhotoValue = analogRead(PhotoPin);
  voltage = PhotoValue * (5.0 / 1023.0);

  // Print voltage in LCD
  lcd.setCursor(0,1); // Column 0, Line 1
  lcd.print(String(voltage) + " V");

  delay(1000);
}