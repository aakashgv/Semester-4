#include<stdio.h>
#include<stdlib.h>
#include"2display.h"



void display(int m){
    printf("%d\t  %d\t\t %d\n",m+1,mark[m][1],mark[m][2]);
    mark[m][0]=1;
    for(i=0;i<n;i++){
        if(g[m][i]==1 && mark[i][0]!=1){
            display(i);
        }
    }
}
