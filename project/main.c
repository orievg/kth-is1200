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
  3, 3, 3, 3, 3, 3, 255, 0,
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
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 255, 0,
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
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 255, 0,
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
	255, 255, 255, 255, 192, 192, 192, 192,
	192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 255, 0,
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
};
uint8_t  icon[] = { // border. other functions alter this.
	255, 255, 255, 255, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 3, 3, 3, 3,
  3, 3, 3, 3, 255, 0, 0, 0,
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
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 0, 0, 0,
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
	255, 255, 255, 255, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 255, 0, 0, 0,
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
	255, 255, 255, 255, 192, 192, 192, 192,
	192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 192, 192, 192, 192, 192,
  192, 192, 192, 0, 255, 0, 0, 0,
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
};
char textbuffer[2][9] = {{'G', 'A', 'M', 'E', ' ', 'O', 'V', 'E', 'R'},{}};
char score_array[4][5] = {{},
                          {},
                          {},
                          {}};
char temp[5];
int max1 = 0, max2 = 0, max3 = 0, max4 = 0;
int timeout= 0;
static const uint8_t const font[] = {
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
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 94, 0, 0, 0, 0,
	0, 0, 4, 3, 4, 3, 0, 0,
	0, 36, 126, 36, 36, 126, 36, 0,
	0, 36, 74, 255, 82, 36, 0, 0,
	0, 70, 38, 16, 8, 100, 98, 0,
	0, 52, 74, 74, 52, 32, 80, 0,
	0, 0, 0, 4, 3, 0, 0, 0,
	0, 0, 0, 126, 129, 0, 0, 0,
	0, 0, 0, 129, 126, 0, 0, 0,
	0, 42, 28, 62, 28, 42, 0, 0,
	0, 8, 8, 62, 8, 8, 0, 0,
	0, 0, 0, 128, 96, 0, 0, 0,
	0, 8, 8, 8, 8, 8, 0, 0,
	0, 0, 0, 0, 96, 0, 0, 0,
	0, 64, 32, 16, 8, 4, 2, 0,
	0, 62, 65, 73, 65, 62, 0, 0,
	0, 0, 66, 127, 64, 0, 0, 0,
	0, 0, 98, 81, 73, 70, 0, 0,
	0, 0, 34, 73, 73, 54, 0, 0,
	0, 0, 14, 8, 127, 8, 0, 0,
	0, 0, 35, 69, 69, 57, 0, 0,
	0, 0, 62, 73, 73, 50, 0, 0,
	0, 0, 1, 97, 25, 7, 0, 0,
	0, 0, 54, 73, 73, 54, 0, 0,
	0, 0, 6, 9, 9, 126, 0, 0,
	0, 0, 0, 102, 0, 0, 0, 0,
	0, 0, 128, 102, 0, 0, 0, 0,
	0, 0, 8, 20, 34, 65, 0, 0,
	0, 0, 20, 20, 20, 20, 0, 0,
	0, 0, 65, 34, 20, 8, 0, 0,
	0, 2, 1, 81, 9, 6, 0, 0,
	0, 28, 34, 89, 89, 82, 12, 0,
	0, 0, 126, 9, 9, 126, 0, 0,
	0, 0, 127, 73, 73, 54, 0, 0,
	0, 0, 62, 65, 65, 34, 0, 0,
	0, 0, 127, 65, 65, 62, 0, 0,
	0, 0, 127, 73, 73, 65, 0, 0,
	0, 0, 127, 9, 9, 1, 0, 0,
	0, 0, 62, 65, 81, 50, 0, 0,
	0, 0, 127, 8, 8, 127, 0, 0,
	0, 0, 65, 127, 65, 0, 0, 0,
	0, 0, 32, 64, 64, 63, 0, 0,
	0, 0, 127, 8, 20, 99, 0, 0,
	0, 0, 127, 64, 64, 64, 0, 0,
	0, 127, 2, 4, 2, 127, 0, 0,
	0, 127, 6, 8, 48, 127, 0, 0,
	0, 0, 62, 65, 65, 62, 0, 0,
	0, 0, 127, 9, 9, 6, 0, 0,
	0, 0, 62, 65, 97, 126, 64, 0,
	0, 0, 127, 9, 9, 118, 0, 0,
	0, 0, 38, 73, 73, 50, 0, 0,
	0, 1, 1, 127, 1, 1, 0, 0,
	0, 0, 63, 64, 64, 63, 0, 0,
	0, 31, 32, 64, 32, 31, 0, 0,
	0, 63, 64, 48, 64, 63, 0, 0,
	0, 0, 119, 8, 8, 119, 0, 0,
	0, 3, 4, 120, 4, 3, 0, 0,
	0, 0, 113, 73, 73, 71, 0, 0,
	0, 0, 127, 65, 65, 0, 0, 0,
	0, 2, 4, 8, 16, 32, 64, 0,
	0, 0, 0, 65, 65, 127, 0, 0,
	0, 4, 2, 1, 2, 4, 0, 0,
	0, 64, 64, 64, 64, 64, 64, 0,
	0, 0, 1, 2, 4, 0, 0, 0,
	0, 0, 48, 72, 40, 120, 0, 0,
	0, 0, 127, 72, 72, 48, 0, 0,
	0, 0, 48, 72, 72, 0, 0, 0,
	0, 0, 48, 72, 72, 127, 0, 0,
	0, 0, 48, 88, 88, 16, 0, 0,
	0, 0, 126, 9, 1, 2, 0, 0,
	0, 0, 80, 152, 152, 112, 0, 0,
	0, 0, 127, 8, 8, 112, 0, 0,
	0, 0, 0, 122, 0, 0, 0, 0,
	0, 0, 64, 128, 128, 122, 0, 0,
	0, 0, 127, 16, 40, 72, 0, 0,
	0, 0, 0, 127, 0, 0, 0, 0,
	0, 120, 8, 16, 8, 112, 0, 0,
	0, 0, 120, 8, 8, 112, 0, 0,
	0, 0, 48, 72, 72, 48, 0, 0,
	0, 0, 248, 40, 40, 16, 0, 0,
	0, 0, 16, 40, 40, 248, 0, 0,
	0, 0, 112, 8, 8, 16, 0, 0,
	0, 0, 72, 84, 84, 36, 0, 0,
	0, 0, 8, 60, 72, 32, 0, 0,
	0, 0, 56, 64, 32, 120, 0, 0,
	0, 0, 56, 64, 56, 0, 0, 0,
	0, 56, 64, 32, 64, 56, 0, 0,
	0, 0, 72, 48, 48, 72, 0, 0,
	0, 0, 24, 160, 160, 120, 0, 0,
	0, 0, 100, 84, 84, 76, 0, 0,
	0, 0, 8, 28, 34, 65, 0, 0,
	0, 0, 0, 126, 0, 0, 0, 0,
	0, 0, 65, 34, 28, 8, 0, 0,
	0, 0, 4, 2, 4, 2, 0, 0,
	0, 120, 68, 66, 68, 120, 0, 0,
};

void alterIcon(x, y){
  // used for next shape feature.
  int i;

  for (i = 0; i < 2; i++){
    int offset = 0;

    if (x > 8)
    {
      offset = x / 8;
    }
    icon[128*offset + y + i] |= 3 << (x - offset*8);
  }
}
void drawO(int x, int y){
  // shape O consists of 4 blocks. (4 x 4)
  // coordinates are the top right corner of shape.
  int X = x + 2;
  int Y = y + 2;

  alterIcon(x, y);
  alterIcon(x, Y);
  alterIcon(X, y);
  alterIcon(X, Y);

}
void drawI(int x, int y){
  // draws the I shape horizontally.
  // coordinates are the top right corner of shape.
  int i;

  for (i = x; i < (x + 8); i = i + 2){
    alterIcon(i, y);
  }
}
void drawJ(int x, int y){
  // draws the J shape horizontally
  int X = x + 2;
  int i;
  alterIcon(x, y);

  for (i = y; i < (y + 6); i = i + 2){
    alterIcon(X, i);
  }
}
void drawL(int x, int y){
  // draws the L shape horizontally
  int X = x + 2;
  int i;
  alterIcon(X, y);

  for(i = y; i < (y + 6); i = i + 2){
    alterIcon(x, i);
  }
}
void drawS(int x, int y){
  int X = x +2;
  int X_neg = x -2;
  int Y = y + 2;

  alterIcon(x, y);
  alterIcon(x, Y);
  alterIcon(X, y);
  alterIcon(X_neg, Y);
}
void drawZ(int x, int y){
  int X = x + 2;
  int X_neg = x - 2;
  int Y = y + 2;

  alterIcon(x, y);
  alterIcon(x, Y);
  alterIcon(X, Y);
  alterIcon(X_neg, y);
}
void drawT(int x, int y){
  int X = x + 2;
  int X_neg = x - 2;
  int Y = y + 2;

  alterIcon(x, y);
  alterIcon(X, Y);
  alterIcon(x, Y);
  alterIcon(X_neg, Y);
}
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
  //  PORTF = 0xFFFF;
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
    drawLine(x, y + i, 3); // 2 pixels per block
  }
}

void FieldToDisplay(){
  // Dalvie
  // int x, y;
  int i, z;

  for (z = 0; z < 21; z++){

    for (i = 0; i < 10; i++){
      if (field[(i + z*10)] == 1){
        drawBlock((i * 2) + 8, (z*2 + 4));
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

  if (nextPiece == 'i'){
  drawI(12, 60);
}
else if (nextPiece == 'o'){
  drawO(12, 60);
}
else if (nextPiece == 'j'){
  drawJ(12, 60);
}
else if (nextPiece == 'l'){
  drawL(12, 60);
}
else if (nextPiece == 's'){
  drawS(12, 60);
}
else if (nextPiece == 'z'){
  drawZ(12, 60);
}
else if (nextPiece == 't'){
  drawT(12, 60);
}

if (pieceOnHold == 'i'){
drawI(12, 67);
}
else if (pieceOnHold == 'o'){
drawO(12, 67);
}
else if (pieceOnHold == 'j'){
drawJ(12, 67);
}
else if (pieceOnHold == 'l'){
drawL(12, 67);
}
else if (pieceOnHold == 's'){
drawS(12, 67);
}
else if (pieceOnHold == 'z'){
drawZ(12, 67);
}
else if (pieceOnHold == 't'){
drawT(12, 67);
}
}
void display_string() {
  char score_char[9];
  int i, j, k;
	int c;
  sprintf(score_char,"SCORE:%i", score);
  for(i = 0; i<9; i++){
    textbuffer[1][i] = score_char[i];
  }

	for(i = 0; i < 2; i++) { //copied from lab.
		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
		spi_send_recv(0x22);
		spi_send_recv(i);

		spi_send_recv(0x0);
		spi_send_recv(0x10);

		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;

		for(j = 0; j < 9; j++) {
			c = textbuffer[i][j];
			if(c & 0x80)
				continue;

			for(k = 0; k < 8; k++)
				spi_send_recv(font[c*8 + k]);
		}
	}
}
int drawMenu(){
  int out = 0;
  int i, j, k, c;
  char menu_1[2][11] = {{'*','S', 'T','A', 'R', 'T'},
                        {' ','H', 'I', 'G', 'H', 'S', 'C', 'O', 'R', 'E', 'S'}};
  char menu_2[2][11] = {{' ','S', 'T','A', 'R', 'T'},
                        {'*','H', 'I', 'G', 'H', 'S', 'C', 'O', 'R', 'E', 'S'}};

  while(1){
    delay(1000000);
    int btns = getBtns();

    if (btns == 4){
      out = 0;
    for(i = 0; i < 2; i++) { //copied from lab.
  		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
  		spi_send_recv(0x22);
  		spi_send_recv(i);

  		spi_send_recv(0x0);
  		spi_send_recv(0x10);

  		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;

  		for(j = 0; j < 11; j++) {
  			c = menu_1[i][j];
  			if(c & 0x80)
  				continue;

  			for(k = 0; k < 8; k++)
  				spi_send_recv(font[c*8 + k]);
        }
  		}
  	}

    if (btns == 2){ // highscore
      out = 1;
    for(i = 0; i < 2; i++) { //copied from lab.
  		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
  		spi_send_recv(0x22);
  		spi_send_recv(i);

  		spi_send_recv(0x0);
  		spi_send_recv(0x10);

  		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;

  		for(j = 0; j < 11; j++) {
  			c = menu_2[i][j];
  			if(c & 0x80)
  				continue;

  			for(k = 0; k < 8; k++)
  				spi_send_recv(font[c*8 + k]);
        }
  		}
  	}

    if (btns == 1){
      rnd = TMR2;
      return out;
      break;
    }
  }
}


int main() {

  int i;
  int direction;
  int menu_out;
  direction = 0;
  int* directionPoint = &direction;

	spi_init();
	display_wakeup();
  Buttoninit();
  while(1){

  menu_out = drawMenu(); // display menu screen
  if (menu_out == 1){ // highscore screen.

    while (1){
      int i, j, k, c;
      for(i = 0; i < 4; i++) { //copied from lab.
    		DISPLAY_COMMAND_DATA_PORT &= ~DISPLAY_COMMAND_DATA_MASK;
    		spi_send_recv(0x22);
    		spi_send_recv(i);

    		spi_send_recv(0x0);
    		spi_send_recv(0x10);

    		DISPLAY_COMMAND_DATA_PORT |= DISPLAY_COMMAND_DATA_MASK;

    		for(j = 0; j < 5; j++) {
    			c = score_array[i][j];
    			if(c & 0x80)
    				continue;

    			for(k = 0; k < 8; k++)
    				spi_send_recv(font[c*8 + k]);
    		}
    	}
      int btns = getBtns();
      if (btns == 1 || btns == 2 || btns == 4){ //return to menu screen.
        break;
      }
    }
  }
  if (menu_out == 0){ // start game.
  pieceName = randomPiece();
  nextPiece = randomPiece();
  ClearScreen();

  for (i=0; i<210; i++){
    field[i] = 0; // for game reset
  }
  spawnPiece(pieceName, pieceState);
  FieldToDisplay();

  Timer2init();

  while(1){
    int btns = getBtns();
    int btn1 = getBTN1();
    if (IFS(0) & 0x100){
      IFSCLR(0) = 0x100;
      timeout++;
}
      if (timeout == 5){
      timeout = 0;
    //  int btns = getBtns();
    //  int btn1 = getBTN1();
      // delay(1000000);

      if (btns == 4){ // right
        direction = 2;
        move(pieceName, pieceState, directionPoint);
      //  ClearScreen();
      //  FieldToDisplay();
        direction = 0;
      }
      else if (btns == 2){ // left
        direction = 1;
      move(pieceName, pieceState, directionPoint);
    //  ClearScreen();
    //  FieldToDisplay();
      direction = 0;
    }
    else if (btns == 1){ // rotate
      rotate(1, pieceName, PState);
      //ClearScreen();
      //FieldToDisplay();
    }
    else if (btn1 == 1){ // hold
        if (pieceOnHold == ' '){
      clrPiece( pieceName, pieceState);
      pieceOnHold = pieceName;
      exchangePieces(PName, Pnext);
      x_ = 5;
      y_ = 0;
      spawnPiece( pieceName, pieceState);
      //ClearScreen();
      //FieldToDisplay();
    }
      else{
      clrPiece( pieceName, pieceState);
      exchangePieces(PName, onHoldP);
      x_ = 5;
      y_ = 0;
      spawnPiece( pieceName, pieceState);
      //ClearScreen();
      //FieldToDisplay();
        }
    }
    else { // default downward movement
      move(pieceName, pieceState, directionPoint);
      //ClearScreen();
      //FieldToDisplay();
    }
    ClearScreen(); // update the screen.
    FieldToDisplay();
      if (done == 1 && (y_ == 1 || y_ == 0)) // gameOver.
        {
        ClearScreen();
        renderScreen(icon);
        done = 0;
        if (max1 < score){ // update highscores.
          max4 = max3;
          max3 = max2;
          max2 = max1;
          max1 = score;
          sprintf(temp, "1.%i", score);
          for(i = 0; i < 5; i++){
          score_array[0][i] = temp[i];
        }
        }
        else if (max2 < score){
          max4 = max3;
          max3 = max2;
          max2 = score;
          sprintf(temp, "2.%i", max2);
          for(i = 0; i < 5; i++){
          score_array[1][i] = temp[i];
        }
        }
        else if (max3 < score){
          max4 = max3;
          max3 = score;
          sprintf(temp, "3.%i", max3);
          for(i = 0; i < 5; i++){
          score_array[2][i] = temp[i];
        }
        }
        else if (max4 < score){
          max4 = score;
          sprintf(temp, "4.%i", max4);
          for(i = 0; i < 5; i++){
          score_array[3][i] = temp[i];
        }
        }

        display_string();
        break;
      }
      else if (done == 1){ // piece can no longer move.
        rowCheck();
        Done();

      }
    }
  }
}
}
	return 0;
}
