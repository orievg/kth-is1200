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
int timeoutcount = 0;
char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void ){
  volatile int* E= (volatile int*) 0xbf886100;

  volatile int* pE= (volatile int*) 0xbf886110;
  *pE = 0x0;
  *pE= *pE+1;
  *E = * E & 0xff00; //init port E
  TRISD = TRISD & 0x0fe0; // init port D

  T2CONCLR =0x0; //disable timer b4 configuring


  T2CONSET = 0x70; //prescale 256 //0111
  TMR2 = 0x0; //set timer to 0
  PR2 = (8000000 / 256); // AKA 80 mil /256/10
  T2CONSET = 0x8000; //timer on

  return;
}

/* This function is called repetitively from the main program */
void labwork( void ){

  int btn = getbtns();
  int sw = getsw();

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
      if(IFS(0) & 0x100){/*Test time-out event flag*/
        timeoutcount++;
        IFSCLR(0) = 0x100;

      }
      if (timeoutcount==10) {
        time2string( textstring, mytime );
        display_string( 3, textstring );
        display_update();
        tick( &mytime );
        display_image(96, icon);
        timeoutcount=0;
      }



}
