#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define FIELD_SIZE 210
#define SMALL_PIECE_SIZE 9
#define LARGE_PIECE_SIZE 16
//



//
// Created by Orievg on 2020-02-26.
//
//piece arguments
int direction =0;
int position = 0;
int x_ = 0;
int y_ = 17;
int drop = 0;
int pieceState = 0;
char pieceName = 'i';
//
int done = 0;
//define field size
    int field[FIELD_SIZE]={0};
//4x4  pieces
    int i_[][LARGE_PIECE_SIZE]={{0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0},{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},{0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0}};
    int o_[][LARGE_PIECE_SIZE]={{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},{0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0}};
//3x3 pieces
    int j_[][SMALL_PIECE_SIZE]={{1,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,1,0},{0,0,0,1,1,1,0,0,1},{0,1,0,0,1,0,1,1,0}};
    int l_[][SMALL_PIECE_SIZE]={{0,0,1,1,1,1,0,0,0},{0,1,0,0,1,0,0,1,1},{0,0,0,1,1,1,1,0,0},{1,1,0,0,1,0,0,1,0}};
    int s_[][SMALL_PIECE_SIZE]={{0,1,1,1,1,0,0,0,0},{0,1,0,0,1,1,0,0,1},{0,0,0,0,1,1,1,1,0},{1,0,0,1,1,0,0,1,0}};
    int t_[][SMALL_PIECE_SIZE]={{0,1,0,1,1,1,0,0,0},{0,1,0,0,1,1,0,1,0},{0,0,0,1,1,1,0,1,0},{0,1,0,1,1,0,0,1,0}};
    int z_[][SMALL_PIECE_SIZE]={{1,1,0,0,1,1,0,0,0},{0,0,1,0,1,1,0,1,0},{0,0,0,1,1,0,0,1,1},{0,1,0,1,1,0,1,0,0}};
    //

//r==1 - clockwise r==2 counterclockwise
void rotate(int r, char piece, int * state){
    if (piece == 'i'){
        if (r == 1){
            if ((*state) == 0)
                (*state) = 1;
            else
                (*state) = 0;
        }
        if (r==2){
            if ((*state) == 0)
                (*state) = 1;
            else
                (*state) = 0;
        }

    }
    if (piece == 'j'||piece == 'l'||piece == 's'||piece == 't'||piece == 'z'){
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
            else
                (*state)=3;

    }

}
void showField(){
    for (int i=10;i<FIELD_SIZE;i++){
        printf("%i",field[i]);
        if ((i+1)%10==0){
            printf(" %i\n", (i+1)/10);
        }
    }
    printf("\n");
}
void clrPiece(char pieceName, int state){
    position = x_+y_*10;
    if (pieceName =='i'){
        for (int i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]-=i_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='o'){
        for (int i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]-=o_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='j'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=j_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='l'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=l_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='s'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=s_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='t'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]-=t_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='z'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
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
    if (pieceName =='i'){
        for (int i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]+=i_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='o'){
        for (int i=0;i<LARGE_PIECE_SIZE;i++){
            field[position]+=o_[state][i];

            if ((i+1)%4==0){
                position+=6;
            }
            position++;
        }
    }
    if (pieceName =='j'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=j_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='l'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=l_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='s'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=s_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='t'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=t_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
    if (pieceName =='z'){
        for (int i=0;i<SMALL_PIECE_SIZE;i++){
            field[position]+=z_[state][i];

            if ((i+1)%3==0){
                position+=7;
            }
            position++;
        }
    }
}
void Done(){
    x_=4;
    y_=17;
    pieceState=0;
    pieceName='i';
    spawnPiece(pieceName,pieceState);
    done = 0;
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
    printf("row: %i, sum=%i\n",row,0);
    int fieldReserve[FIELD_SIZE]={0};
    int j=FIELD_SIZE;
    for (int i = FIELD_SIZE; i>10;i--){

        if (row*10==i){
            i-=10;
            printf("%i",i);
        }
        fieldReserve[j]=field[i];
        j--;
    }
    for (int i=10;i<FIELD_SIZE;i++){
        field[i]=fieldReserve[i];
    }
}
void collisionCheck(char pieceName, int state,int direction){
    int coord_1 = x_+y_*10;
    int coord_2 = x_+1+y_*10;
    int coord_3 = x_+2+y_*10;
    int coord_14 = x_+3+y_*10;

    int coord_4 = x_+(y_+1)*10;
    int coord_5 = x_+1+(y_+1)*10;
    int coord_6 = x_+2+(y_+1)*10;
    int coord_15 = x_+3+(y_+1)*10;

    int coord_7 = x_+(y_+2)*10;
    int coord_8 = x_+1+(y_+2)*10;
    int coord_9 = x_+2+(y_+2)*10;
    int coord_16 = x_+3+(y_+2)*10;

    int coord_10 = x_+(y_+3)*10;
    int coord_11 = x_+1+(y_+3)*10;
    int coord_12 = x_+2+(y_+3)*10;
    int coord_13 = x_+3+(y_+3)*10;
    //coord_1=position = x_+y_*10;
    if (direction==1){

    }
    if (direction==2){

    }
    if (direction==0){
        if (pieceName=='o' && state==0){
            if (field[coord_11]==1 || field[coord_12]==1){
                done =1;
            }
        }
        if (pieceName=='i' && state==0){
            if (field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1|| field[coord_16]==1){
                done =1;
            }
        }
        if (pieceName=='i' && state==1){
            if (field[x_+2+(y_+4)*10]==1){
                done =1;
            }
        }
        if (pieceName=='i' && state==2){
            if (field[coord_10]==1 || field[coord_11]==1 || field[coord_12]==1|| field[coord_13]==1){
                done =1;
            }
        }
        if (pieceName=='i' && state==3){
            if (field[x_+1+(y_+4)*10]==1){
                done =1;
            }
        }
        if (pieceName=='j' && state==0){
            if (field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1){
                done =1;
            }
        }
        if (pieceName=='j' && state==1){
            if (field[coord_11]==1 || field[coord_6]==1){
                done =1;
            }
        }
        if (pieceName=='j' && state==2){
            if (field[coord_7]==1 || field[coord_8]==1 || field[coord_12]==1){
                done =1;
            }
        }
        if (pieceName=='j' && state==3){
            if (field[coord_10]==1 || field[coord_11]==1){
                done =1;
            }
        }
        if (pieceName=='l' && state==0){
            if (field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1){
                done =1;
            }
        }
        if (pieceName=='l' && state==1){
            if (field[coord_11]==1 || field[coord_12]==1){
                done =1;
            }
        }
        if (pieceName=='l' && state==2){
            if (field[coord_10]==1 || field[coord_8]==1 || field[coord_9]==1){
                done =1;
            }
        }
        if (pieceName=='l' && state==3){
            if (field[coord_4]==1 || field[coord_11]==1){
                done =1;
            }
        }
        if (pieceName=='s' && state==0){
            if (field[coord_7]==1 || field[coord_8]==1 || field[coord_6]==1){
                done =1;
            }
        }
        if (pieceName=='s' && state==1){
            if (field[coord_8]==1 || field[coord_12]==1){
                done =1;
            }
        }
        if (pieceName=='s' && state==2){
            if (field[coord_10]==1 || field[coord_11]==1 || field[coord_9]==1){
                done =1;
            }
        }
        if (pieceName=='s' && state==3){
            if (field[coord_7]==1 || field[coord_8]==1){
                done =1;
            }
        }
        if (pieceName=='t' && state==0){
            if (field[coord_7]==1 || field[coord_8]==1 || field[coord_9]==1){
                done =1;
            }
        }
        if (pieceName=='t' && state==1){
            if (field[coord_8]==1 || field[coord_6]==1){
                done =1;
            }
        }
        if (pieceName=='t' && state==2){
            if (field[coord_7]==1 || field[coord_11]==1 || field[coord_9]==1){
                done =1;
            }
        }
        if (pieceName=='t' && state==3){
            if (field[coord_7]==1 || field[coord_11]==1){
                done =1;
            }
        }
        if (pieceName=='z' && state==0){
            if (field[coord_4]==1 || field[coord_8]==1 || field[coord_9]==1){
                done =1;
            }
        }
       if (pieceName=='z' && state==1){
           if (field[coord_8]==1 || field[coord_6]==1){
               done =1;
           }
       }
        if (pieceName=='z' && state==2){
            if (field[coord_7]==1 || field[coord_11]==1 || field[coord_12]==1){
                done =1;
            }
        }
        if (pieceName=='z' && state==3){
            if (field[coord_10]==1 || field[coord_8]==1){
                done =1;
            }
        }
    }
}
void boundCheck(char pieceName, int state,int direction){
    //left collision
    if (direction==2){
        //upper left check return 1 if movement possible or 0 if not
        if (pieceName == 'j'||pieceName == 'l'||pieceName == 's'||pieceName == 't'||pieceName == 'z'){
            if (state == 1){
                //can move 1 time left
            }
            else if (x_==0||x_%10==0){
                //goes down
                x_++;
                y_++;
            }
        }
        else if (pieceName=='i'){
           if (state==0||state==2){
               //goes down
               x_++;
               y_++;
           }
           else if (state==1 &&x_==-2){
               //goes down
               x_++;
               y_++;
           }
           else if (state==3 &&x_==-1){
               //goes down
               x_++;
               y_++;
           }
        }
        else
            if (x_==-1){
                //goes down
                x_++;
                y_++;
            }
    }
    //right collision
    if (direction==1){
        if (pieceName == 'j'||pieceName == 'l'||pieceName == 's'||pieceName == 't'||pieceName == 'z') {
            if (state == 3){
                //can move 1 time right
            }
            else if ((x_+2)%10==0){
                //goes down
                x_--;
                y_++;
            }
        }
        else if (pieceName=='i'){
            if (state==0||state==2){
                //goes down
                x_++;
                y_++;
            }
            else if (state==1 &&(x_+3)%10==0){
                //goes down
                x_++;
                y_++;
            }
            else if (state==3 &&(x_+2)%10==0){
                //goes down
                x_++;
                y_++;
            }
        }
        else
        if ((x_+3)%10==0){
            //goes down
            x_++;
            y_++;
        }
    }
    if (direction==0){
        if (pieceName == 'j'||pieceName == 'l'||pieceName == 's'||pieceName == 't'||pieceName == 'z'){
            if (state==0){
                //can move 1 down
            }
           if (y_==19){
                done = 1;
            }
        }
        if (pieceName == 'i'){
            if ((state==0&& y_==19)||(state==3&&y_==18)){
                    done = 1;
            }
            else{
                if (y_==17){
                    done = 1;
                }
            }

        }
        if (pieceName == 'i'){
            if ((state==0&& y_==19)||(state==3&&y_==18)) done = 1;

            else{
                if (y_==17) done = 1;

            }

        }
        else
            if (y_==18)done = 1;
    }


}
void move(char pieceName, int state,int direction){
    position = x_+y_*10;
    clrPiece(pieceName, state);

        if (direction==0){
            y_++;
            boundCheck(pieceName,state,direction);
            collisionCheck(pieceName, state, direction);
            spawnPiece(pieceName,state);
        }
        else if (direction == 1){
            x_++;
            boundCheck(pieceName,state,direction);
            collisionCheck(pieceName, state, direction);
            spawnPiece(pieceName,state);
        }
        else if (direction == 2){

            x_--;
            boundCheck(pieceName,state,direction);
            spawnPiece(pieceName,state);
        }


}
void rowCheck(){
    int sum = 0;
    for (int i = 1;i<22;i++){
        for (int j=0;j<10;j++){
            sum+=field[i*10+j];
        }
        if (sum==10) {
            clearRow(i+1);

        }
            sum=0;
    }
}
void tick(float sec)
{
    // Converting time into milli_seconds
    int ms = 1000 * sec;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + ms);
}
//void displayPiece(char pieceName, int state){
//    if (pieceName == 'i'){
//        for(int i=0;i<16;i++){
//            printf("%i", i_[state][i]);
//            if ((i+1)%4==0){
//                printf("\n");
//            }
//        }
//    }
//    if (pieceName == 'j'){
//        for(int i=0;i<SMALL_PIECE_SIZE;i++){
//            printf("%i", j_[state][i]);
//            if ((i+1)%3==0){
//                printf("\n");
//            }
//        }
//    }
//    if (pieceName == 'l'){
//        for(int i=0;i<SMALL_PIECE_SIZE;i++){
//            printf("%i", l_[state][i]);
//            if ((i+1)%3==0){
//                printf("\n");
//            }
//        }
//    }
//    if (pieceName == 's'){
//        for(int i=0;i<SMALL_PIECE_SIZE;i++){
//            printf("%i", s_[state][i]);
//            if ((i+1)%3==0){
//                printf("\n");
//            }
//        }
//    }
//    if (pieceName == 't'){
//        for(int i=0;i<SMALL_PIECE_SIZE;i++){
//            printf("%i", t_[state][i]);
//            if ((i+1)%3==0){
//                printf("\n");
//            }
//        }
//    }
//    if (pieceName == 'z'){
//        for(int i=0;i<SMALL_PIECE_SIZE;i++){
//            printf("%i", z_[state][i]);
//            if ((i+1)%3==0){
//                printf("\n");
//            }
//        }
//    }
//
//}
int quit = 11;
void main(){
    time_t ti;
    /* Intializes random number generator */
    srand((unsigned) time(&ti));
//    int shape = rand() % 7;
//    char piece;
//    if (shape ==0){piece='o';}
//    if (shape ==1){piece='i';}
//    if (shape ==2){piece='j';}
//    if (shape ==3){piece='l';}
//    if (shape ==4){piece='s';}
//    if (shape ==5){piece='t';}
//    if (shape ==6){piece='z';}
//
//    int * stateP = &pieceState;
//    displayPiece(piece, pieceState);
//    printf("Rotating right\n");
//    rotate(1,piece,stateP);
//    displayPiece(piece, pieceState);
//    printf("\n");
    showField();

    //int dir =2;
    spawnPiece(pieceName,pieceState);
    showField();
    int done1= 0;
    while (quit!=1 && done!=1){
        tick(1);
        printf("Tick\n");
        move(pieceName,pieceState, 0);
        printf("x=%i, y=%i\n",x_,y_);
        showField();
        rowCheck();
        quit--;

        if (done ==1 && done1==0){
            printf("done\n");
            Done();
            done1++;
        }
        else if (done ==1 && done1==1){
            printf("done\n");
            DoneDone();
        }
    }
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
//    displayPiece(piece, pieceState);


}
