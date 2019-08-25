#include<stdio.h>
#include<stdlib.h>
#include"3display.h"



void display(int top){
    int m;
    while(top!=-1){
        m=pop();
        if(mark[m][0]!=1){
            printf("%d",m+1);
            displaypart(m);
        }
        printf("\n");
    }
}
