#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<unistd.h> 

int main(int argc,char* argv[]){
int i;
int n=atoi(argv[1]);
 for(i=0;i<n;i++){
  if(fork()==0){
  printf("\n hi i am a process in fork and you have called me %d times\n",i+1);
          exit(0);    }
                 }
return 0;
                             }
