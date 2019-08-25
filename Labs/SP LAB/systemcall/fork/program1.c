 #include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<unistd.h> 
#include<sys/types.h> 

int main(){
int A,B,C; 
printf("\n welcome to program 1");
printf("\n_____________________\n");
         
         if(fork()==0){
          A=getpid();
          printf("\nMY PROCESS ID IS-%d",A);
          
          B=getppid();
          printf("\nMY PARENTs PROCESS ID IS-%d",B);
                     }          
         else{
         sleep(2);
         C=getppid();
         printf("\nMY GRANDPARENT PROCESS ID IS-%d",C);
             } 
return 0;
}             

