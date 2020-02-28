//
// Created by Orievg on 2020-02-27.
//
#include<stdio.h>
#include<stdlib.h>
int randomPiece(){
    int *r;
    r = (int*)malloc(sizeof(int));
    int number = ((int)r%7);
    return number;
}
int randomState(){
    int  x= -1;
    int * xP = &x;
    while ((*xP)==-1){
        int *r;
        r = (int*)malloc(sizeof(int));
        (*xP) = ((int)r%5-1);
     }
    return(*xP);
}
int randomOffset(){
    int  x= -1;
    int * xP = &x;
        int *r;
        r = (int*)malloc(sizeof(int));
        (*xP) = ((int)r%7);
    return (*xP);
}
void main(){
    for (int i=0;i<100;i++){
    printf("%i\n",randomPiece());}
}