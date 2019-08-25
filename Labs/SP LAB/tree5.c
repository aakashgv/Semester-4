#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
  
int main() 
{ 

    if(fork() == 0) 
        { 
            printf("Child PID: %d Parent PID: %d\n",getpid(),getppid()); 
          

    for(int i=0;i<2;i++) 
    { 
        if(fork() == 0) 
        { 
            printf("Child PID: %d Parent PID: %d\n",getpid(),getppid()); 
            exit(0); 
        } 
    } 
    for(int i=0;i<2;i++) 
    wait(NULL); 
   	
     exit(0); 
        } 
      
} 

