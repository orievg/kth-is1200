/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
	int* led;
  led = 0xbf886100;
  *led &= ~ 0xff; // set 8 lsb of PORTE to 0 (output)

  TRISD &= 0x7f0; // set bits 7-11 as 1 (intputs)

}

/* This function is called repetitively from the main program */
void labwork( void )
{
	int* out;
  volatile int val;
  volatile int btns;
	out =  0xbf886110;
	*out = 0;

  	delay( 1000 );
  	time2string( textstring, mytime );
  	display_string( 3, textstring );
  	display_update();
  	tick( &mytime );
  	*out++;
  	display_image(96, icon);

    while(1){
      // checks push btns and updates appropriate digit.
      btns = getbtns();
      val = getsw();

      if ((btns && 0x1) == 1) {
        val = val || 0xff0f; // sets all other bits to 1.
        mytime = (mytime || 0x00f0) && val; // copies val to mytime
      }
      if (((btns && 0x2) >> 1) == 1) {
        val = val || 0xf0ff; // sets all other bits to 1.
        mytime = (mytime || 0x0f00) && val; // copies val to mytime
      }
      if (()(btns && 0x4) >> 2) == 1) {
        val = val || 0x0fff; // sets all other bits to 1.
        mytime = (mytime || 0xf000) && val; // copies val to mytime
      }
    }
}
