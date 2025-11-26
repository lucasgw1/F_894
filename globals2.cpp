#include "globals2.h"


////
// LCD Connection Variables
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

////
// Button Variables
const int upPin = 3;
const int downPin = 2;
const int selectPin = 4;

////
// Navigation Variables
int cursor = 0;
int startIdx = 0;
int menuState = 0;

int yellowPin = 5;
int yellowState = 0;


////
// Menu Variables
void openSub1() {menuState = 1; cursor = 0;}
void openSub2() {menuState = 2; cursor = 0;}
void openSub3() {menuState = 3; cursor = 0;}
void openSub4() {menuState = 4; cursor = 0;}
void openSub5() {menuState = 5; cursor = 0;}
void goBack() {menuState = menulist[menuState].parent; cursor = 0;}
void yellowLed() {
  digitalWrite(yellowPin, yellowState ? HIGH : LOW);
  yellowState = !yellowState;
}

const char* mainItens[] = {"Option 1", "Option 2", "Option 3", "Option 4", "Option 5"};
const char* sub1Itens[] = {"Yellow Led", "Back"};
const char* sub2Itens[] = {"Back"};
const char* sub3Itens[] = {"Back"};
const char* sub4Itens[] = {"Back"};
const char* sub5Itens[] = {"Back"};

MenuAction mainActions[] = {openSub1, openSub2, openSub3, openSub4, openSub5};
MenuAction sub1Actions[] = {yellowLed, goBack};
MenuAction sub2Actions[] = {goBack};
MenuAction sub3Actions[] = {goBack};
MenuAction sub4Actions[] = {goBack};
MenuAction sub5Actions[] = {goBack};

Menu menulist[] = {
  {mainItens, mainActions, ARRAY_SIZE(mainItens), -1},
  {sub1Itens, sub1Actions, ARRAY_SIZE(sub1Itens), 0},
  {sub2Itens, sub2Actions, ARRAY_SIZE(sub2Itens), 0},
  {sub3Itens, sub3Actions, ARRAY_SIZE(sub3Itens), 0},
  {sub4Itens, sub4Actions, ARRAY_SIZE(sub4Itens), 0},
  {sub5Itens, sub5Actions, ARRAY_SIZE(sub5Itens), 0},
};

