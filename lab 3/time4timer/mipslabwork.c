/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

  Dalvie
  time4timer Assn 2/lab 2

  This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;
int timeoutcount = 0;
char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
	volatile int* led = (volatile int*) 0xbf886100; // TRISE
  *led &= ~ 0xff; // set 8 lsb of TRISE to 0 (output)


  TRISDSET = 0x7f0; // set bits 7-11 as 1 (intputs)


  T2CON = 0x70; // sets the timer to off and prescale to 1:256
  PR2 = (80000000 / 256) / 10; // timeout every 100ms
  TMR2 = 0; // reset the timer
  T2CONSET = 0x8000; // start the timer
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
  volatile int* out = (volatile int*) 0xbf886110; // PORTE
  *out = 0;
   // iterate the output (led) by 1.
   int val = getsw();
   int btns = getbtns();

   while(1){
     btns = getbtns();
     val = getsw();
      // when btn 2 is pressed. 001,011,101,111 update  first second
      if (btns == 1 || btns == 3 || btns == 5 || btns == 7) {
        mytime = ((mytime & 0xff0f) | (val << 4));
      }
      // when btn 3 is pressed 010, 110, 011, 111 update last minute
      if (btns == 2 || btns == 6 || btns == 3 || btns == 7) {
        mytime = ((mytime & 0xf0ff) | (val << 8));
      }
      // when btn 4 is pressed 100, 101, 110, 111
      if (btns == 4 || btns == 5 || btns == 6 || btns == 7) {
        mytime = ((mytime & 0x0fff) | (val << 12));
      }

      if (IFS(0) & 0x100) { //check for timeout IF.
        timeoutcount++;
        IFSCLR(0) = 0x100; // clear the timeout IF.
    }
      if (timeoutcount == 10){
        timeoutcount = 0;
        time2string( textstring, mytime );
      	display_string( 3, textstring );
      	display_update();
      	tick( &mytime );
      	//*out = *out + 1;
      	display_image(96, icon);
        *out = *out + 1;
      }
      }
    }
