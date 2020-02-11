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
void labinit( void ){
  volatile int* E= (volatile int*) 0xbf886100;
  *E = * E & 0xff00; //init port E
  TRISD = TRISD & 0xfe0; // init port D
  return;
}

/* This function is called repetitively from the main program */
void labwork( void ){
  volatile int* pE= (volatile int*) 0xbf886110;
  *pE = 0;
  int btn = getbtns();
  int sw = getsw();

  while (1) {
    delay( 1000 );
    btn = getbtns();
    sw = getsw();
    //button 4 // 100,101,110,111
      if (btn ==4||btn ==5||btn ==6||btn ==7) {
        mytime = (mytime & 0x0fff) | (sw<<12);
      }
      //button 3 010,011,110,111
      if (btn ==2||btn ==3||btn ==6||btn ==7) {
        mytime = (mytime & 0xf0ff) | (sw<<8);
      }
      //button 2 001,011,101,111
      if (btn ==1||btn ==3||btn ==5||btn ==7) {// 100,101,110,111
        mytime = (mytime & 0xff0f) | (sw<<4);
      }
      time2string( textstring, mytime );
      display_string( 3, textstring );
      display_update();
      tick( &mytime );
      display_image(96, icon);
      *pE= *pE+1;

  }
}
