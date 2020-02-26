#include <stdio.h>
//
// Created by Orievg on 2020-02-19.
//
int main(void){
    int display[64][128];
    for (int i = 0;i<64;i++){
        for (int j = 0;j<128;j++){
            display[i][j]=1;
        }
    }
    for (int i = 0;i<64;i++){
        for (int j = 0;j<128;j++){
            printf("%p ",display[i][j]);
        }
    }
}

