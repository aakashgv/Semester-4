 #include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h> 
#include<unistd.h> 
#include<sys/types.h> 

int main(){
int i,sume,sumo; 
printf("\n welcome to program 2");
printf("\n_____________________\n");
        
         if(fork()==0){
         
         for(i=1;i<=20;i++){
           if(i%2==0){
           sume+=i;
                     }
                           }
                      
          printf("\n the sum of even numbers from 1->20 is:%d",sume);
            
                      
                      }
         else{
         for(i=1;i<=20;i++){
           if(i%2!=0){
           sumo+=i;
                     }
         
                           }
          printf("\n the sum of odd numbers from 1->20 are-%d",sumo);
             } 
return 0;
}
