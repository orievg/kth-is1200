#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// #include <time.h>
#define FIELD_SIZE 210
#define SMALL_PIECE_SIZE 9
#define LARGE_PIECE_SIZE 16
//



//
// Created by Orievg on 2020-02-26.
//
//piece arguments
int rot = 0;//rotation of an object
int position = 0;
int x_ = 0;
int y_ = 0; //-1 form desired row
int drop = 0;
int pieceState = 1;
char pieceName = 'i';
int pieceDirection = 0;
int quit = 11;
//
int done = 0;
//define field size
int field[FIELD_SIZE]={0};
int fieldReserve[FIELD_SIZE]={0};
//4x4  pieces
int i_[][LARGE_PIECE_SIZE]={{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0}};
int o_[][LARGE_PIECE_SIZE]={{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}};
//3x3 pieces
int j_[][SMALL_PIECE_SIZE]={{1,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,1,0},{0,0,0,1,1,1,0,0,1},{0,1,0,0,1,0,1,1,0}};
int l_[][SMALL_PIECE_SIZE]={{0,0,1,1,1,1,0,0,0},{0,1,0,0,1,0,0,1,1},{0,0,0,1,1,1,1,0,0},{1,1,0,0,1,0,0,1,0}};
int s_[][SMALL_PIECE_SIZE]={{0,1,1,1,1,0,0,0,0},{0,1,0,0,1,1,0,0,1},{0,0,0,0,1,1,1,1,0},{1,0,0,1,1,0,0,1,0}};
int t_[][SMALL_PIECE_SIZE]={{0,1,0,1,1,1,0,0,0},{0,1,0,0,1,1,0,1,0},{0,0,0,1,1,1,0,1,0},{0,1,0,1,1,0,0,1,0}};
int z_[][SMALL_PIECE_SIZE]={{1,1,0,0,1,1,0,0,0},{0,0,1,0,1,1,0,1,0},{0,0,0,1,1,0,0,1,1},{0,1,0,1,1,0,1,0,0}};
//

//r==1 - clockwise r==2 counterclockwise
/*
void showField(){
    for (int i=10;i<FIELD_SIZE;i++){
        printf("%i",field[i]);
        if ((i+1)%10==0){
            printf(" %i\n", (i+1)/10);
        }
    }
    printf("\n");
}
*/

void clrPiece(char pieceName, int state){
    position = x_+y_*10;
    int i;
    if (pieceName =='i'){
        for (i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]-=i_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='o'){
        for (i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]-=o_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='j'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=j_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='l'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=l_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='s'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=s_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='t'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=t_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='z'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=z_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
}
void spawnPiece(char pieceName, int state){
    position = x_+y_*10;
    int i;

    if (pieceName =='i'){
        for (i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]+=i_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='o'){
        for (i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]+=o_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='j'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=j_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='l'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=l_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='s'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=s_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='t'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=t_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='z'){
        for (i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=z_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
}
void rotate(int r, char piece, int * state){
    clrPiece(piece,(*state));
    if (r == 1){
        if ((*state)<3){
            (*state)++;
        }
        else
            (*state)=0;

    }
    if (r==2)
        if ((*state)>0){
            (*state)--;
        }
        else{
            (*state)=3;
          }
    spawnPiece(piece,(*state));
}
void Done(){
    done = 0;
    x_=5;
    y_=0;
    pieceState=0;
    pieceDirection = 0;
    pieceName='z';
    spawnPiece(pieceName,pieceState);

}
void DoneDone(){
    x_=7;
    y_=14;
    pieceState=0;
    pieceName='o';
    spawnPiece(pieceName,pieceState);
    done = 0;
}
void clearRow(int row){
  //  printf("row: %i, sum=%i\n",row,0);
    int i;
    int j=FIELD_SIZE;
    for ( i = FIELD_SIZE; i>10;i--){

        if (row*10==i){
            i-=10;
        //    printf("%i",i);
        }
        fieldReserve[j]=field[i];
        j--;
    }
    for ( i=10;i<FIELD_SIZE;i++){
        field[i]=fieldReserve[i];
    }
}
void collisionCheck(char pieceName, int state,int * direction){
    position = x_+y_*10;

    //coord_1=position = x_+y_*10;
    if ((*direction)==2){
        int coord_1 = position;
        int coord_2 = position+1;
        int coord_3 = position+2;
        int coord_14 = position+3;

        int coord_4 = position+10;
        int coord_5 = position+11;
        int coord_6 = position+12;
        int coord_15 = position+13;

        int coord_7 = position+19;
        int coord_8 = position+20;
        int coord_9 = position+21;
        int coord_16 = position+22;

        int coord_10 = position+29;
        int coord_11 = position+30;
        int coord_12 = position+31;
        int coord_13 = position+32;
        if (pieceName=='o' ){
            if (field[coord_1]==1||field[coord_4]==1){
                (*direction) = 0;
            }
        }

        if (pieceName=='i' ){
            if (state==0){
                if (field[coord_4-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_2]==1 || field[coord_5]==1 || field[coord_8]==1|| field[coord_11]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_7-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_1]==1 || field[coord_4]==1 || field[coord_7]==1|| field[coord_10]==1){
                    (*direction) = 0;
                }
            }
        }

        if (pieceName=='j' ){
            if (state==0){
                if (field[coord_1-1]==1 || field[coord_4-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_1]==1 || field[coord_4]==1 || field[coord_7]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_4-1]==1|| field[coord_8]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_1]==1 || field[coord_4]==1 || field[coord_7-1]==1){
                    (*direction) = 0;
                }
            }
        }

        if (pieceName=='l' ){
            if (state==0){
                if (field[coord_2]==1 || field[coord_4-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_1]==1 || field[coord_4]==1 || field[coord_7]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_4-1]==1|| field[coord_7-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_1-1]==1 || field[coord_4]==1 || field[coord_7]==1){
                    (*direction) = 0;
                }
            }
        }

        if (pieceName=='s' ){
            if (state==0){
                if (field[coord_1]==1 || field[coord_4-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_1]==1 || field[coord_4]==1 || field[coord_8]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_4]==1|| field[coord_7-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_1-1]==1 || field[coord_4-1]==1 || field[coord_7]==1){
                    (*direction) = 0;
                }
            }
        }

        if (pieceName=='t' ){
            if (state==0){
                if (field[coord_1]==1 || field[coord_4-1]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_1]==1 || field[coord_4]==1 || field[coord_7]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_4-1]==1|| field[coord_7]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_1]==1 || field[coord_4-1]==1 || field[coord_7]==1){
                    (*direction) = 0;
                }
            }
        }

        if (pieceName=='z' ){
            if (state==0){
                if (field[coord_1-1]==1 || field[coord_4]==1){
                    (*direction) = 0;
                  //  printf("DIR CHANGED");
                }
            }
            if (state==1){
                if(field[coord_2]==1 || field[coord_4]==1 || field[coord_7]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_4-1]==1|| field[coord_7]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_1]==1 || field[coord_4-1]==1 || field[coord_7-1]==1){
                    (*direction) = 0;
                }
            }
        }
    }
    if ((*direction)==1){
        int coord_1 = position-1;
        int coord_2 = position;
        int coord_3 = position+1;
        int coord_14 = position+2;

        int coord_4 = position+9;
        int coord_5 = position+10;
        int coord_6 = position+11;
        int coord_15 = position+12;

        int coord_7 = position+19;
        int coord_8 = position+20;
        int coord_9 = position+21;
        int coord_16 = position+22;

        int coord_10 = position+29;
        int coord_11 = position+30;
        int coord_12 = position+31;
        int coord_13 = position+32;
        if (pieceName=='i' ){
            if (state==0){
                if (field[coord_15+1]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_14]==1 || field[coord_15]==1 || field[coord_16]==1|| field[coord_13]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_16+1]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_3]==1 || field[coord_6]==1 || field[coord_9]==1|| field[coord_12]==1){
                    (*direction) = 0;
                }
            }
        }
        if (pieceName=='j' ){
            if (state==0){
                if (field[coord_2]==1 || field[coord_15]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_14]==1 || field[coord_6]==1|| field[coord_9]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_15]==1 || field[coord_16]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_3]==1 || field[coord_6]==1 || field[coord_9]==1){
                    (*direction) = 0;
                }
            }
        }
        if (pieceName=='l' ){
            if (state==0){
                if (field[coord_14]==1 || field[coord_15]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_3]==1 || field[coord_6]==1|| field[coord_16]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_8]==1 || field[coord_16]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_3]==1 || field[coord_6]==1 || field[coord_9]==1){
                    (*direction) = 0;
                }
            }
        }
        if (pieceName=='s' ){
            if (state==0){
                if (field[coord_14]==1 || field[coord_6]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_3]==1 || field[coord_15]==1|| field[coord_16]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_9]==1 || field[coord_16]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_2]==1 || field[coord_6]==1 || field[coord_9]==1){
                    (*direction) = 0;
                }
            }
        }
        if (pieceName=='t' ){
            if (state==0){
                if (field[coord_3]==1 || field[coord_15]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_3]==1 || field[coord_15]==1|| field[coord_9]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_9]==1 || field[coord_16]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_3]==1 || field[coord_6]==1 || field[coord_9]==1){
                    (*direction) = 0;
                }
            }
        }
        if (pieceName=='z' ){
            if (state==0){
                if (field[coord_3]==1 || field[coord_15]==1){
                    (*direction) = 0;
                }
            }
            if (state==1){
                if(field[coord_14]==1 || field[coord_15]==1|| field[coord_9]==1){
                    (*direction) = 0;
                }
            }
            if (state==2){
                if (field[coord_6]==1 || field[coord_16]==1){
                    (*direction) = 0;
                }
            }
            if (state==3){
                if(field[coord_3]==1 || field[coord_6]==1 || field[coord_8]==1){
                    (*direction) = 0;
                }
            }
        }
        if (pieceName=='o' ){
            if (field[coord_15]==1 || field[coord_16]==1){
                done =1;
            }
        }
    }
    if ((*direction)==0){
        int coord_1 = position-10;
        int coord_2 = position-9;
        int coord_3 = position-8;
        int coord_14 = position-7;

        int coord_4 = position;
        int coord_5 = position+1;
        int coord_6 = position+2;
        int coord_15 = position+3;

        int coord_7 = position+10;
        int coord_8 = position+11;
        int coord_9 = position+12;
        int coord_16 = position+13;

        int coord_10 = position+20;
        int coord_11 = position+21;
        int coord_12 = position+22;
        int coord_13 = position+23;
        if (pieceName=='o' ){
            if (field[coord_11]==1 || field[coord_12]==1){
                done =1;
            }
        }
        if (pieceName=='i' ){
            if (state==0){
                if (field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1|| field[coord_16]==1){
                    done = 1;
                }
            }
            if (state==1){
                if(field[x_+2+(y_+4)*10]==1){
                    done = 1;
                }
            }
            if (state==2){
                if (field[coord_10]==1 || field[coord_11]==1 || field[coord_12]==1|| field[coord_13]==1){
                    done = 1;
                }
            }
            if (state==3){
                if(field[x_+1+(y_+4)*10]==1){
                    done = 1;
                }
            }
        }
        if (pieceName=='j' ){
            if (state==0){
                if (field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1){
                    done = 1;
                }
            }
            if (state==1){
                if(field[coord_11]==1 || field[coord_6]==1){
                    done = 1;
                }
            }
            if (state==2){
                if (field[coord_7]==1 || field[coord_8]==1 || field[coord_12]==1){
                    done = 1;
                }
            }
            if (state==3){
                if(field[coord_10]==1 || field[coord_11]==1){
                    done = 1;
                }
            }
        }
        if (pieceName=='l' ){
            if (state==0){
                if (field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1){
                    done = 1;
                }
            }
            if (state==1){
                if(field[coord_11]==1 || field[coord_12]==1){
                    done = 1;
                }
            }
            if (state==2){
                if (field[coord_10]==1 || field[coord_8]==1 || field[coord_9]==1){
                    done = 1;
                }
            }
            if (state==3){
                if(field[coord_4]==1 || field[coord_11]==1){
                    done = 1;
                }
            }
        }
        if (pieceName=='s' ){
            if (state==0){
                if (field[coord_7]==1 || field[coord_8]==1 || field[coord_6]==1){
                    done = 1;
                }
            }
            if (state==1){
                if(field[coord_8]==1 || field[coord_12]==1){
                    done = 1;
                }
            }
            if (state==2){
                if (field[coord_10]==1 || field[coord_11]==1 || field[coord_9]==1){
                    done = 1;
                }
            }
            if (state==3){
                if(field[coord_7]==1 || field[coord_8]==1){
                    done = 1;
                }
            }
        }
        if (pieceName=='t' ){
            if (state==0){
                if (field[coord_3]==1 || field[coord_15]==1){
                    done = 1;
                }
            }
            if (state==1){
                if(field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1){
                    done = 1;
                }
            }
            if (state==2){
                if (field[coord_7]==1 || field[coord_11]==1 || field[coord_9]==1){
                    done = 1;
                }
            }
            if (state==3){
                if(field[coord_7]==1 || field[coord_11]==1){
                    done = 1;
                }
            }
        }
        if (pieceName=='z' ){
            if (state==0){
                if (field[coord_4]==1 || field[coord_8]==1 || field[coord_9]==1){
                    done = 1;
                }
            }
            if (state==1){
                if(field[coord_8]==1 || field[coord_6]==1){
                    done = 1;
                }
            }
            if (state==2){
                if (field[coord_7]==1 || field[coord_11]==1 || field[coord_12]==1){
                    done = 1;
                }
            }
            if (state==3){
                if(field[coord_10]==1 || field[coord_8]==1){
                    done = 1;
                }
            }
        }
    }
}
void boundCheck(char pieceName, int state,int * direction){
    //left collision

    if ((*direction)==2){
        //upper left check return 1 if movement possible or 0 if not
        if (pieceName == 'j'||pieceName == 'l'||pieceName == 's'||pieceName == 't'||pieceName == 'z'){
            if (state == 1){
                //can move 1 time left
            }
            else if (x_==0||x_%10==0){
                (*direction) = 0;
            }
        }
        else if (pieceName=='i'){
            if (state==0||state==2){
                (*direction) = 0;
            }
            else if (state==1 &&x_==-2){
                (*direction) = 0;
            }
            else if (state==3 &&x_==-1){
                (*direction) = 0;
            }
        }
        else if (pieceName=='o'){
            if (x_==-1){
                (*direction) = 0;
            }
        }

    }
        //right collision
    else if ((*direction)==1){
        if (pieceName == 'j'||pieceName == 'l'||pieceName == 's'||pieceName == 't'||pieceName == 'z') {
            if (state == 3){
                //can move 1 time right
            }
            else if ((x_+2)%10==0){
                //goes down
                (*direction) = 0;
            }
        }
        else if (pieceName=='i'){
            if (state==0||state==2){
                //goes down
                (*direction) = 0;
            }
            else if (state==1 &&(x_+3)%10==0){
                //goes down
                (*direction) = 0;
            }
            else if (state==3 &&(x_+2)%10==0){
                //goes down
                (*direction) = 0;
            }
        }
        else if (pieceName=='o'){
            //goes down
            if  ((x_+3)%10==0){
                (*direction) = 0;
            }
        }
    }
    else if ((*direction)==0){
        if (pieceName == 'j'||pieceName == 'l'||pieceName == 's'||pieceName == 't'||pieceName == 'z'){
            if (state==0 &&y_==20){
                done = 1;
            }
            else if (y_==19){
                done = 1;
            }
        }
        else if (pieceName == 'i'){
            if ((state==0 && y_==19)||(state==3 && y_==18)){
                done = 1;
            }
            else{
                if (y_==17){
                    done = 1;
                }
            }

        }
        else if (pieceName == 'o'){
            if  (y_==18){
                done = 1;
            }
        }
    }

}
void move(char pieceName, int state,int * direction){
    position = x_+y_*10;
    clrPiece(pieceName, state);
    if ((*direction) == 0){

        y_++;
        boundCheck(pieceName,state,direction);
        collisionCheck(pieceName, state, direction);
        boundCheck(pieceName,state,direction);
//        if (direction!=0){
//            y_--;
//        }
    }
    else if ((*direction) == 1){
        x_++;
        boundCheck(pieceName,state,direction);
        collisionCheck(pieceName, state, direction);
        boundCheck(pieceName,state,direction);
        if ((*direction)!=1){
            x_--;
        }
    }
    else if ((*direction) == 2){
        x_--;
        boundCheck(pieceName,state,direction);
        collisionCheck(pieceName, state, direction);
        boundCheck(pieceName,state,direction);
        if ((*direction)!=2){
            x_++;
        }
    }
    spawnPiece(pieceName,state);


}
void rowCheck(){
    int sum = 0;
    int i, j;
    for ( i = 1;i<22;i++){
        for ( j=0;j<10;j++){
            sum+=field[i*10+j];
        }
        if (sum==10) {
            clearRow(i+1);

        }
        sum=0;
    }
}

/*
void tick(float sec)
{
    // Converting time into milli_seconds
    int ms = 1000 * sec;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + ms);
}
*/


/*
void main(){
  int * stateP = &pieceState;
  int * directionP = &pieceDirection;
  int i;
  spawnPiece('i', 1);
  showField();
  move('i', 1, directionP);
  showField();

  for (i = 0; i < 16; i++){
    move('i', 1, directionP);
    showField();
  }
  //  time_t ti;
    // Intializes random number generator
// srand((unsigned) time(&ti));
//    int shape = rand() % 7;

    showField();


    //int dir =2;


    spawnPiece(pieceName,pieceState);
    showField();
    int done1= 0;
    while (quit!=1 && done!=1){
      //  tick(1);
        printf("Tick\n");
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
        printf("x=%i, y=%i, piece: %c, direction: %i, done %i\n",x_,y_, pieceName, (*directionP), done);
        showField();
        rowCheck();
        quit--;

        if (done == 1){
            Done();
        }



      }

}
*/
