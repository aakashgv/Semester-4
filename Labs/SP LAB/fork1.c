#include  <stdio.h>
#include  <string.h>
#include  <math.h>
#include  <ctype.h>
#include  <sys/types.h>

void main(){

	if (fork()==0){
		if (fork()==0){			
			if (fork()==0){
				printf("My process ID : %d\n", getpid());
				}
			else{
				wait();
				printf("My father process ID : %d\n", getpid());}
			}
	
	else{
			wait();
			printf("My grandfather process ID : %d\n", getpid());
		}}	
			
		
		
		}
				
		

