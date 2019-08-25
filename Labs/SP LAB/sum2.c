#include<stdio.h>
void main(){
	int n,i,sum;
	printf("Enter the value for n:  ");
	scanf("%d",&n);
	
	if (fork() == 0){
		sum=0;
		for (i=1;i<n+1;i++){
			if (i%2!=0){
				sum+=i;
				}
				}
		printf("The sum of all odd numbers is %d \n",sum);
		}
	else if(fork()!=0){
		sum=0;
		for (i=1;i<n+1;i++){
			if (i%2==0){
				sum+=i;
				}}
		printf("The sum of all even numbers is %d \n",sum);
		}
		}
	
	
		 
