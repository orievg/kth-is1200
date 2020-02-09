#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"


int getsw(void){
    int sw = (PORTD>>8) & 0x000f; //use only last 4bits
    return sw;
}

int getbtns(void){
    int btn = (PORTD>>5) & 0x0007; // take data from switches
    return btn;
}
