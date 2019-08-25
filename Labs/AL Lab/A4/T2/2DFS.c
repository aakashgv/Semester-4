#include"2DFS.h"

int n=50;
int init=1;

void DFS(int m){
    mark[m][1]=init++;
    mark[m][0]=1;
    for(i=0;i<n;i++){
        if(g[m][i]==1 && mark[i][0]!=1){
            DFS(i);
        }
        else if(g[m][i]==1 && mark[i][0]==1){
            printf("Cycle seen between %d and %d\n",m+1,i+1);
        }
    }
    mark[m][2]=init++;
    
}
