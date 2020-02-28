#include <pic32mx.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "test.h"


#define DISPLAY_VDD PORTFbits.RF6
#define DISPLAY_VBATT PORTFbits.RF5
#define DISPLAY_COMMAND_DATA PORTFbits.RF4
#define DISPLAY_RESET PORTGbits.RG9


#define DISPLAY_VDD_PORT PORTF
#define DISPLAY_VDD_MASK 0x40
#define DISPLAY_VBATT_PORT PORTF
#define DISPLAY_VBATT_MASK 0x20
#define DISPLAY_COMMAND_DATA_PORT PORTF
#define DISPLAY_COMMAND_DATA_MASK 0x10
#define DISPLAY_RESET_PORT PORTG
#define DISPLAY_RESET_MASK 0x200

uint8_t  COPY[] = { // array used for updating screen.
	255, 255, 255, 255, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 255, 255,
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 255, 255,
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 255, 255,
	255, 255, 255, 255, 192, 192, 192, 192,
	192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 255, 255,
};
uint8_t  icon[] = { // border. other functions alter this.
	255, 255, 255, 255, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 255, 255,
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 255, 255,
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 255, 255,
	255, 255, 255, 255, 192, 192, 192, 192,
	192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 255, 255,
};


void delay(int cyc) {
    int i;
    for(i = cyc; i > 0; i--);
}

uint8_t spi_send_recv(uint8_t data) {
    while(!(SPI2STAT & 0x08));
    SPI2BUF = data;
    while(!(SPI2STAT & 0x01));
    return SPI2BUF;
}

void spi_init() {
    /* Set up peripheral bus clock */
    OSCCON &= ~0x180000;
    OSCCON |= 0x080000;

    /* Set up output pins */
    AD1PCFG = 0xFFFF;
    ODCE = 0x0;
    TRISECLR = 0xFF;
    PORTE = 0x0;

    /* Output pins for display signals */
    PORTF = 0xFFFF;
    PORTG = (1 << 9);
    ODCF = 0x0;
    ODCG = 0x0;
    TRISFCLR = 0x70;
    TRISGCLR = 0x200;

    /* Set up input pins */
    TRISDSET = (1 << 8);
    TRISFSET = (1 << 1);

    /* Set up SPI as master */
    SPI2CON = 0;
    SPI2BRG = 4;

    /* Clear SPIROV*/
    SPI2STATCLR &= ~0x40;
    /* Set CKP = 1, MSTEN = 1; */
        SPI2CON |= 0x60;

    /* Turn on SPI */
    SPI2CONSET = 0x8000;
}

void display_wakeup() {
    DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
    delay(10);
    DISPLAY_VDD_PORT &= ~DISPLAY_VDD_MASK;
    delay(1000000);

    spi_send_recv(0xAE);
    DISPLAY_RESET_PORT &= ~DISPLAY_RESET_MASK;
    delay(10);
    DISPLAY_RESET_PORT |= DISPLAY_RESET_MASK;
    delay(10);

    spi_send_recv(0x8D);
    spi_send_recv(0x14);

    spi_send_recv(0xD9);
    spi_send_recv(0xF1);

    DISPLAY_VBATT_PORT &= ~DISPLAY_VBATT_MASK;
    delay(10000000);

    spi_send_recv(0xA1);
    spi_send_recv(0xC8);

    spi_send_recv(0xDA);
    spi_send_recv(0x20);

    spi_send_recv(0xAF);
}

void renderScreen(uint8_t arr[]) {
    int i, j;

    for(i = 0; i < 4; i++) {
        DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
        spi_send_recv(0x22);
        spi_send_recv(i);

        spi_send_recv(0 & 0xF);
        spi_send_recv(0x10 | ((0 >> 4) & 0xF));

        DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;

        for(j = 0; j < 128; j++)
            spi_send_recv(arr[i*128 + j]);
    }
}

void drawLine( int x, int y, int width){
  // draws a line of length width. Helper function for drawBlocks.
  int offset = 0;

  if (x > 8)
  {
    offset = x / 8;
  }
  icon[128*offset + y] |= width << (x - offset*8);

  renderScreen(icon);
}

void drawBlock(int x, int y){
  // x, y is the top left corner. Fixed width of 2 pixels
  // helper function for shapes
  int i;

  for (i = 0; i < 2; i++){
    drawLine(x, y + i, 3);
  }
}

void drawO(int x, int y){
  // shape O consists of 4 blocks. (4 x 4)
  // coordinates are the top right corner of shape.
  int X = x + 2;
  int Y = y + 2;

  drawBlock(x, y);
  drawBlock(x, Y);
  drawBlock(X, y);
  drawBlock(X, Y);

}

void drawI(int x, int y){
  // draws the I shape horizontally.
  // coordinates are the top right corner of shape.
  int i;

  for (i = x; i < (x + 8); i = i + 2){
    drawBlock(i, y);
  }
}

void drawJ(int x, int y){
  // draws the J shape horizontally
  int X = x + 2;
  int i;
  drawBlock(x, y);

  for (i = y; i < (y + 6); i = i + 2){
    drawBlock(X, i);
  }
}

void drawL(int x, int y){
  // draws the L shape horizontally
  int X = x + 2;
  int i;
  drawBlock(X, y);

  for(i = y; i < (y + 6); i = i + 2){
    drawBlock(x, i);
  }
}

void Timer2init(){
  T2CON = 0x70; // sets the timer to off and prescale to 1:256
  PR2 = (80000000 / 256)/10 ; // timeout every 100ms
  TMR2 = 0; // reset the timer
  T2CONSET = 0x8000; // start the timer
}

void FieldToDisplay(){
  // Dalvie
  int x, y;
  int i, z;

  for (z = 0; z < 21; z++){

    for (i = 0; i < 10; i++){
      if (field[(i + z*10)] == 1){
        drawBlock((i * 2) + 2, (z*2 + 4));
      }
    }
}
}

void ClearScreen(){
  int i;
  for (i = 0; i < 512; i++)
  {
    icon[i] = COPY[i];
  }

  renderScreen(icon);
}

int main() {

  int i;
  int direction;
  direction = 0;
  int* directionPoint = &direction;

	spi_init();
	display_wakeup();
  spawnPiece('i', 1);
  FieldToDisplay();
  Timer2init();

  while(1){
    if (IFS(0) & 0x100){
      IFSCLR(0) = 0x100;
      move(pieceName, pieceState, directionPoint);
      delay(10000000);
      ClearScreen();
      FieldToDisplay();
      if (done == 1){
        Done();
      }
  }
}

/*
  int * stateP = &pieceState;
  int * directionP = &pieceDirection;

  int done1= 0;

  while (quit!=1 && done!=1){
      if (IFS(0) & 0x100){
      IFSCLR(0) = 0x100;
      if (quit==5){
          pieceDirection=2;
      }
      if (rot >0){
          rotate(rot,pieceName,stateP);
      }
      else if (pieceDirection>0){
          move(pieceName,pieceState, directionP);
      }
      if (pieceDirection==0) {
          move(pieceName,pieceState, directionP);
      }

      rowCheck();
      quit--;

      if (done == 1){
          Done();
      }
    }
  } */

	return 0;
}
