 #include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<unistd.h> 
#include<sys/types.h> 

int main(){
int p1,p2,c1,c2;
printf("\n welcome to program 5");
printf("\n_____________________\n");
      
         if(fork()==0){
         p1=getppid();
         c1=getpid();
         printf("\n child process 1 with process id %d and my parent's process id is %d\n",c1,p1);
         }
         else{
         	if(fork()==0){
         	p2=getppid();
            c2=getpid();
         printf("\n child process 2 with process id %d and my parent's process id is %d",c2,p2);
         	         	}
         	 } 
         	 
return 0;
}         	 
       
