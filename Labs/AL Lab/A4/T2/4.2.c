#include<stdio.h>
#include<stdlib.h>
#include"2DFS.h"
#include"2display.h"

//gcc -c 2DFS.c
//gcc -c 2display.c
//gcc -c 4.2.c

int stack[100];
int top=-1;


void push(int data){
    stack[++top]=data;
}
int pop(){
    return stack[top--];
}



int main(){
    int n;
    printf("Number of vertices:  ");
    scanf("%d",&n);
   
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){
            mark[i][j]=0;
        }
    }
        
    int op,m,k;
    op =rand()%(n^2 -n);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            g[i][j]=0;
        }
    }
        
    for(i=0;i<op;i++){
        m=rand()%(n);
        k=rand()%(n);
        if(m!=k){
            g[m][k]=1;
        }
    }
    for(i=0;i<=n;i++){
        printf("%d\t",i);
    }
    printf("\n");
    m=1;
    for(i=0;i<n;i++){
        printf("%d\t",m++);
        for(j=0;j<n;j++){
            printf("%d\t",g[i][j]);
        }
        printf("\n");
    }
    
    printf("Enter starting vertex:  ");
    scanf("%d",&m);
    m--;
    
    DFS(m);
    for(i=0;i<n;i++){
        mark[i][0]=0;
        
    }
    
printf("\nNodes   Arrival Time     Completion Time");
printf("\n_____   ___________      _____________\n");
display(m);
 return 0;
    }
