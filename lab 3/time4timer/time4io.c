#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int getsw(void){
  // returns the status of the toggle switches in the 4 lsb
  int rtn = (PORTD >> 8) & 0xf;
  return rtn;
}

int getbtns(void){
  // returns the current value of the push buttons in the 3 lsb
  int rtn = (PORTD >> 5) & 0x7;
  return rtn;
}
