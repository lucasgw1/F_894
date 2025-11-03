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
extern int cursor, menuState;

extern int yellowPin;
extern int yellowState;


////
// Menu Variables
struct Menu {
  const char** options;
  MenuAction* actions; 
  int itemCount;
  int parent;
};

extern void openSub1();
extern void openSub2();
extern void openSub3();
extern void openSub4();
extern void openSub5();
extern void goBack();
extern void yellowLed();

extern const char* mainItens[];
extern const char* sub1Itens[];
extern const char* sub2Itens[];
extern const char* sub3Itens[];
extern const char* sub4Itens[];
extern const char* sub5Itens[];

extern MenuAction mainActions[];
extern MenuAction sub1Actions[];
extern MenuAction sub2Actions[];
extern MenuAction sub3Actions[];
extern MenuAction sub4Actions[];
extern MenuAction sub5Actions[];

extern Menu menulist[];


#endif  