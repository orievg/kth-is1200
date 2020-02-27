#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #include <time.h>
#define FIELD_SIZE 210
#define SMALL_PIECE_SIZE 9
//



//
// Created by Orievg on 2020-02-26.
//
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
/*
void main(){

     time_t ti;
    // Intializes random number generator
    /srand((unsigned) time(&ti));
    int shape = rand() % 7;
    char piece;
    if (shape ==0){piece='o';}
    if (shape ==1){piece='i';}
    if (shape ==2){piece='j';}
    if (shape ==3){piece='l';}
    if (shape ==4){piece='s';}
    if (shape ==5){piece='t';}
    if (shape ==6){piece='z';}

    int pieceState = 0;
    int * stateP = &pieceState;
    displayPiece(piece, pieceState);
    printf("Rotating right\n");
    rotate(1,piece,stateP);
    displayPiece(piece, pieceState);
    printf("\n");
    showField();

    spawnPiece('t',0);
    showField();
    y_++;
    moveDown('t',0);
    showField();
    y_++;
    moveDown('t',0);
    showField();
    */
//    while (quit!=1){
//        tick(1);
//        printf("Tick\n");
//    }
//    for (int j = 0; j<4;j++){
//        for(int i=0;i<9;i++) {
//            printf("%i", z_[j][i]);
//            if ((i + 1) % 3 == 0) {
//                printf("\n");
//            }
//        }
//        printf("\n");
//    }
//    printf("Rotating right\n");
//    rotate(1,piece,stateP);
//    displayPiece(piece, pieceState);
//    printf("Rotating right\n");
//    rotate(1,piece,stateP);
//    displayPiece(piece, pieceState);
//    printf("Rotating right\n");
//    rotate(1,piece,stateP);
//    displayPiece(piece, pieceState);
//    printf("Rotating right\n");
//    rotate(1,piece,stateP);
//    displayPiece(piece, pieceState);}
