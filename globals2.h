#ifndef GLOBALS_H
#define GLOBALS_H

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

typedef void (*MenuAction)();

////
// Libraries
#include <Arduino.h>
#include <LiquidCrystal.h>

////
// LCD Connection Variables
extern const int rs, en, d4, d5, d6, d7;
extern LiquidCrystal lcd;

////
// Button Variables
extern const int upPin, downPin, selectPin;


////
// Navigation Variables
extern int cursor, startIdx, menuState;



////
// Menu Variables
struct Menu {
  const char** options;
  MenuAction* actions; 
  int itemCount;
  int parent;
};

extern String resultado;
extern const int photoPin;


extern void openSub1();
extern void openSub2();
extern void goBack();
extern void medir();
extern void nada();

extern const char* mainItens[];
extern const char* sub1Itens[];
extern const char* sub2Itens[];

extern MenuAction mainActions[];
extern MenuAction sub1Actions[];
extern MenuAction sub2Actions[];

extern Menu menulist[];


#endif  