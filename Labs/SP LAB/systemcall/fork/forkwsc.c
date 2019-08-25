#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<unistd.h> 
#include<sys/types.h> 

int main(){
int i,j,A,B,C,sume,sumo;
int p1,p2,c1,c2;
int ch,choice;

begin:

printf("\n MAIN MENU");
printf("\n__________");
printf("\n1.process id program");
printf("\n2.using fork for addition of odd and even numbers 1-20");
printf("\n3.orphan and zombie process");
printf("\n4.process tree");

printf("\n please enter your choice-");
scanf("%d",&ch);

switch(ch){
case 1:  printf("\n welcome to program 1");
         printf("\n_____________________\n");
         
         if(fork()==0){
          A=getpid();
          printf("\nMY PROCESS ID IS-%d",A);
          
          B=getppid();
          printf("\nMY PARENTs PROCESS ID IS-%d",B);
                     }          
         else{
         C=getppid();
         printf("\nMY GRANDPARENT PROCESS ID IS-%d",C);
             }
         break;
case 2:  printf("\n welcome to program 2");
         printf("\n_____________________");
        
         if(fork()==0){
         
         for(i=1;i<=20;i++){
           if(i%2==0){
           sume+=i;
                     }
                           }
                      
          printf("\n the sum of even numbers from 1->20 are-%d",sume);
            
                      
                      }
         else{
         for(i=1;i<=20;i++){
           if(i%2!=0){
           sumo+=i;
                     }
         
                           }
          printf("\n the sum of odd numbers from 1->20 are-%d",sumo);
             } 
             
          break;
case 3:  printf("\n welcome to program 3");
         printf("\n_____________________");
         printf("\n for Zombie process-\n\n");
         
         if(fork()>0){    //parent process
          printf("\n Hi ! i am the parent process");
          printf("\n I am slightly sleepyso...zzZZZ");
          sleep(50);
          printf("\n slept for too long ");
                        }
         else{
         printf("\n enterd child going to terminate");
         exit(0);
         }
         
        printf("\n zombie process has been created");

        
        printf("\n for orphan process-\n\n");
         
         if(fork()>0){    //parent process
          printf("\n Hi ! i am the parent process");
          printf("\n nice meeting you but bye bye :) ");
                        }
         else{
          sleep(50);
         printf("\n enterd child ");
         
         }
         
        printf("\n orphan process has been created");
         break;
case 4: printf("\n welcome to program 5");
         printf("\n_____________________");
      
         if(fork()==0){
         p1=getppid();
         c1=getpid();
         printf("\n child process 1 with process id %d and my parent's process id is %d",c1,p1);
         }
         else{
         	if(fork()==0){
         	p2=getppid();
            c2=getpid();
         printf("\n child process 2 with process id %d and my parent's process id is %d",c2,p2);
         	         	}
         	 }
       
        break;
default: printf("\n wrong choice please enter again");
}

printf("\n\ndo you want to continue(yes:0|no:1)-");
scanf("%d",&choice);

if(choice==0){
goto begin;
}
else{
printf("\n thanks for running the program");
}

return 0;
}
