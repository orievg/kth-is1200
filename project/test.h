// functions declarations from test.c
#define FIELD_SIZE 210
#include <string.h>

void rotate(int r, char piece, int * state);
void clrPiece(char pieceName, int state);
void spawnPiece(char pieceName, int state);
void displayPiece(char pieceName, int state);
void Done();
void DoneDone();
void clearRow(int row);
void collisionCheck(char pieceName, int state,int direction);
void boundCheck(char pieceName, int state,int direction);
void move(char pieceName, int state,int * direction);
void rowCheck();


extern int field[FIELD_SIZE];
extern int quit;
extern int rot;//rotation of an object
extern int position;
extern int x_;
extern int y_; //-1 form desired row
extern int drop;
extern int pieceState;
extern char pieceName;
extern int pieceDirection;
//
extern int done;
extern int quit;
