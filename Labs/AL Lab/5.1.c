#include<stdio.h>
#include<stdlib.h>

int queue[50],mia[50][50];
int i,j,k,a=0;
int init=0;
int rear=-1;
int front=-1;
int g[50][50],n=60,v;
int num;
void enqueue(int x){
	if(rear==n){
     printf("\n the queue is overflowing");
                }
   else{
       
        queue[++rear]=x;
       }
                    }

int dequeue(){
   if(front>rear){
    printf("\n the queue is underflowing");
    exit(0);                           }
   else{
        int t=queue[++front];
      printf("\n %d\t  %d\t\t\t %d",t,mia[t][1],++a);
      return queue[front];
      }
             }

void bfs(int k){
    enqueue(k);
    mia[k][1]=++init;
    int m;    
    while(front<rear){
        m=dequeue();
        mia[m][0]=1;
        ++init;
        for(i=1;i<n;i++){
           if((g[m][i]==1)&&(mia[i][0]!=1)){
           	   enqueue(i);
                 mia[i][1]=++init;
                  mia[i][0]=1;          	
                                            }
           	            }
        
        
        	                                     
                }
}
        


int main(){

 printf("\n enter any value for number of vertices(max 50)- ");
  scanf("%d",&n);
  
       for(j=0;j<n;j++){
          if(i==0){
           
          }
         g[0][j]=j; 
       }
     
     
       for(i=0;i<n;i++){
         g[i][0]=i; 
       }
   
    g[0][0]=0;
    
  for(i=1;i<n;i++){
    for(j=1;j<n;j++){
       num=rand()%2;
        if( ((num==0)||(num==1)) &&(i!=j)){
        g[i][j]=num;      
                              }  
         
                    }
                  
                  }

   printf("\n the randomly generated graph represented by matrix is - \n");
   
   for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    
       printf("\t%d",g[i][j]);  
                    }
        printf("\n");
                  
                  }


for(i=0;i<n;i++){
	for(j=0;j<n;j++){
    mia[i][j]=0;
                     }
                }

printf("\nenter the node you want to perform bfs from- ");
scanf("%d",&v);


printf("\n bfs o/p  discovery time  sequence  ");
printf("\n________  _____________   _________  ");
bfs(v);






return 0;
           }
