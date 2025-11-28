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


////
// Menu Variables
const int photoPin = A0;
String resultado = "R: ---";

void openSub1() {menuState = 1; cursor = 0;}
void openSub2() {menuState = 2; cursor = 0;}
void goBack() {menuState = menulist[menuState].parent; cursor = 0;}
void medir() {
  int sensor = analogRead(photoPin);
  float voltage = sensor * (5.0/1023.0);

  if (voltage >= 0.2) {
    resultado = "R: Adulterado";
  }
  else {
    resultado = "R: Normal";
  }

}
void nada() {}


const char* mainItens[] = {"Etanol/Metanol", "Gas/Metanol"};
const char* sub1Itens[] = {"Medir", resultado.c_str(), "Voltar"};
const char* sub2Itens[] = {"Voltar"};


MenuAction mainActions[] = {openSub1, openSub2};
MenuAction sub1Actions[] = {medir, nada, goBack};
MenuAction sub2Actions[] = {goBack};


Menu menulist[] = {
  {mainItens, mainActions, ARRAY_SIZE(mainItens), -1},
  {sub1Itens, sub1Actions, ARRAY_SIZE(sub1Itens), 0},
  {sub2Itens, sub2Actions, ARRAY_SIZE(sub2Itens), 0},
};

