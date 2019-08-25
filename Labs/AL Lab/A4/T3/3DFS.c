#include<stdio.h>
#include<stdlib.h>
#include"3DFS.h"

int n=50;
int t=1;
int i,j;


void DFS(int m){
    mark[m][1]=t++;
    mark[m][0]=1;
    for(i=0;i<n;i++){
        if(g[m][i]==1 && mark[i][0]!=1){
            
            DFS(i);
            
        }
    }
    mark[m][2]=t++;
    push(m);
}
