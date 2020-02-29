
#include <pic32mx.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "test.h"

void Timer2init(){
  T2CON = 0x70; // sets the timer to off and prescale to 1:256
  PR2 = (80000000 / 256)/10 ; // timeout every 100ms
  TMR2 = 0; // reset the timer
  T2CONSET = 0x8000; // start the timer
}
void Buttoninit(){ // put in other c file
    TRISDSET = 0xfe0;
    TRISFSET  = 0x2;
}
int getBtns(){ // put in other c file
  int btns = (PORTD >> 5) & 0x7;
  return btns;
}
int getBTN1() {
  int btns = (PORTF & 0x2) >> 0x1;
  return btns;
}
