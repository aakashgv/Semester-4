 #include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<unistd.h> 
#include<sys/types.h> 

int main(){
int A,B;
 printf("\n welcome to program 3");
         printf("\n_____________________\n\n");
         printf("\n for Zombie process-\n");
         
         if(fork()>0){    //parent process
          printf("\n Hi! i am the parent process");
          A=getpid();
          printf("my process id is-%d",A);
          sleep(9);

                        }
         else{
         printf("\n entered child going to terminate\n");
         exit(0);
         }
         
        printf("\n zombie process %d has been created\n",A);

        
        printf("\n for orphan process-\n");
         
         if(fork()>0){    //parent process
          printf("\n Hi ! i am the parent process in orphan process part\n");
                    }
         else{
         printf("\n entered child process for orphan process");
         B=getpid();
         printf("\n the process id of the child process is %d",B);
          sleep(5);
                 
         }
         
        printf("\n orphan process %d has been created",B);
        
}
        
