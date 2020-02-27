#include <pic32mx.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
// #include "test.c"

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

uint8_t game[128*4] = {0};

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

void lightUpPixel(int x, int y) {
    short offset = 0;
    if (y > 0) { offset = y / 8; }
    game[offset * 128 + x] |= 1 << (y - offset * 8);
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


// Evegnii code here.


#define FIELD_SIZE 210
#define SMALL_PIECE_SIZE 9

int x_ = 0;
int y_ = 0;
//define field size
    int field[FIELD_SIZE]={0};
//4x4  pieces
    int i_[][16]={{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0}};
    int o_[][16]={{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}};
//3x3 pieces
    int j_[][SMALL_PIECE_SIZE]={{1,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,1,0},{0,0,0,1,1,1,0,0,1},{0,1,0,0,1,0,1,1,0}};
    int l_[][SMALL_PIECE_SIZE]={{0,0,1,1,1,1,0,0,0},{0,1,0,0,1,0,0,1,1},{0,0,0,1,1,1,1,0,0},{1,1,0,0,1,0,0,1,0}};
    int s_[][SMALL_PIECE_SIZE]={{0,1,1,1,1,0,0,0,0},{0,1,0,0,1,1,0,0,1},{0,0,0,0,1,1,1,1,0},{1,0,0,1,1,0,0,1,0}};
    int t_[][SMALL_PIECE_SIZE]={{0,1,0,1,1,1,0,0,0},{0,1,0,0,1,1,0,1,0},{0,0,0,1,1,1,0,1,0},{0,1,0,1,1,0,0,1,0}};
    int z_[][SMALL_PIECE_SIZE]={{1,1,0,0,1,1,0,0,0},{0,0,1,0,1,1,0,0,0},{0,0,0,1,1,0,0,1,1},{0,1,0,1,1,0,1,0,0}};
    //
    int quit = 0;
//r==1 - clockwise
void rotate(bool r, char piece, int * state){
    if (piece == 'i'){
        if (r == 1){
            if ((*state) == 0)
                (*state) = 1;
            else
                (*state) = 0;
        }
        else{
            if ((*state) == 0)
                (*state) = 1;
            else
                (*state) = 0;
        }

    }
    if (piece == 'j'||piece == 'l'||piece == 's'||piece == 't'||piece == 'z'){
        if (r==1){
            if ((*state)<3){
                (*state)++;
            }
            else
                (*state)=0;

        }
        else
            if ((*state)>0){
                (*state)--;
            }
            else
                (*state)=3;

    }

}

/*
void showField(){
  int i;
    for ( i=0;i<FIELD_SIZE;i++){
        printf("%i",field[i]);
        if ((i+1)%10==0){
            printf("\n");
        }
    }
    printf("\n");
}
*/

void clrPiece(char pieceName){}
void spawnPiece(char pieceName, int state){
  int i;
    int position = x_+y_*10;
    if (pieceName =='t'){
        for ( i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]=t_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
}
void moveDown(char pieceName, int state){
    int i;
    int position = x_+y_*10;
    if (pieceName =='t'){
        //clearing the row above
        for ( i=0;i<3;i++){
            field[position-10+i]=0;
        }
        spawnPiece(pieceName,state);
    }
}
//fuction to move sideways r=1 - right
void moveSide(char pieceName, int state, int r){
  int i;
    int position = x_+y_*10;
    if (pieceName =='t'&&state==0){
        //clearing the row above
        for ( i=0;i<3;i++){
            field[position-10+i]=0;
        }
        spawnPiece(pieceName,state);
    }
}

/*
 void tick(int sec)
 {
    // Converting time into milli_seconds
    int ms = 1000 * sec;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + ms);
} */

/*
void displayPiece(char pieceName, int state){
  int i;
    if (pieceName == 'i'){
        for( i=0;i<16;i++){
            printf("%i", i_[state][i]);
            if ((i+1)%4==0){
                printf("\n");
            }
        }
    }
    if (pieceName == 'j'){
        for( i=0;i<SMALL_PIECE_SIZE;i++){
            printf("%i", j_[state][i]);
            if ((i+1)%3==0){
                printf("\n");
            }
        }
    }
    if (pieceName == 'l'){
        for( i=0;i<SMALL_PIECE_SIZE;i++){
            printf("%i", l_[state][i]);
            if ((i+1)%3==0){
                printf("\n");
            }
        }
    }
    if (pieceName == 's'){
        for( i=0;i<SMALL_PIECE_SIZE;i++){
            printf("%i", s_[state][i]);
            if ((i+1)%3==0){
                printf("\n");
            }
        }
    }
    if (pieceName == 't'){
        for( i=0;i<SMALL_PIECE_SIZE;i++){
            printf("%i", t_[state][i]);
            if ((i+1)%3==0){
                printf("\n");
            }
        }
    }
    if (pieceName == 'z'){
        for( i=0;i<SMALL_PIECE_SIZE;i++){
            printf("%i", z_[state][i]);
            if ((i+1)%3==0){
                printf("\n");
            }
        }
    }

}
*/
void updateDisplay(){
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

int main() {
  int i;
	spi_init();
	display_wakeup();




  spawnPiece('t',0);
  updateDisplay();

	return 0;
}
