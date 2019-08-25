#include<stdio.h>
#include<stdlib.h>
#include"3DFS.h"
#include"3display.h"

int stack[100];

int i,j;
int g[50][50];
int mark[50][3];
int trans[50][50];

void push(int data){
    stack[++top]=data;
}
int pop(){
    return stack[top--];
}

void displaypart(int m){
    int n;
    mark[m][0]=1;
    for(i=0;i<n;i++){
        if(trans[m][i]==1 && mark[i][0]!=1){
            printf(" - %d",i+1);
            displaypart(i);
        }
    }
}

void main(){
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
    
    printf("Enter starting point of DFS:  ");
    scanf("%d",&m);
    m--;
    DFS(m);
    for(i=0;i<n;i++){
        if(mark[i][0]==0){
            DFS(i);
        }
    }
    for(i=0;i<n;i++){
        mark[i][0]=0;
       
    }
    
    for(i=0;i<op;i++){
        for(j=0;j<n;j++){
            if(g[i][j]==1){
                trans[j][i]=1;
            }
        }
    }
    printf("Strongly connected nodes are: \n");
    display();
    printf("\nNode  Discovery Time Ending Time\n");
    
    for(i=0;i<n;i++){
        printf("%d\t  %d\t\t %d\n",i+1,mark[i][1],mark[i][2]);
    }
}
