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

//volatile int* out = (volatile int*) 0xbf886110; // PORTE
//volatile int* led = (volatile int*) 0xbf886100;
  volatile int* E= (volatile int*) 0xbf886100;
    volatile int* pE= (volatile int*) 0xbf886110;




int mytime = 0x5957;
int timeoutcount = 0;
char textstring[] = "text, more text, and even more text!";
int prime = 1234567;

/* Interrupt Service Routine */
void user_isr( void ){
	if (IFS(0) & 0x100){
	timeoutcount++;
  	if(timeoutcount == 10){
  		time2string( textstring, mytime );
  		display_string( 3, textstring );
  		display_update();
  		tick( &mytime );
  		timeoutcount = 0;
	}
	//IFSCLR(0) = 0x100;
	IFS(0)=0;
}
	if(IFS(0) & 0x80100){
	*E = * E & 0xff00; //init port E
	*pE= *pE+0x1;
	//IFSCLR(0) = 0x100000;
	IFS(0)=0;
}
  /*

  */


/* Interrupt Service Routine */
void user_isr( void )
{
  timeoutcount++;
  if(timeoutcount == 10) {
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );
  timeoutcount = 0;
}
  IFSCLR(0) = 0x100;

  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{

*E = * E & 0xff00; //init port E
*pE = 0;
 //IPC/ TRISE
   // set 8 lsb of TRISE to 0 (output)
 //sw4 should add one to this.
  //

  TRISDSET= 0x7f0; // set bits 7-11 as 1 (intputs)

	volatile int* led = (volatile int*) 0xbf886100; // TRISE
  *led &= ~ 0xff; // set 8 lsb of TRISE to 0 (output)
  volatile int* out = (volatile int*) 0xbf886110; // PORTE
  *out = 0; //sw4 should add one to this.
  // *out = *out + 1;

  TRISD &= 0xfe0; // set bits 7-11 as 1 (intputs)



  T2CON = 0x70; // sets the timer to off and prescale to 1:256
  PR2 = (80000000 / 256) / 10; // timeout every 100ms
  TMR2 = 0; // reset the timer
  IPC(2) = (0x4 << 2);

  IPC(4) = 0x1c000000;
  IEC(0) = (0x80100);
  INTCON=0x10;

  IEC(0) = (0x1 << 8);

  T2CONSET = 0x8000; // start the timer
  enable_interrupt();
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
   prime = nextprime(prime);
   display_string(0, itoaconv(prime));
   display_update();
}
