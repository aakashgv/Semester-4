#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 7

void main()
{
	
	int i,edge;
	printf("0,1\n");
	srand(time(0));
	for(i=2;i<n;i++)
	{
		edge=rand()%i;
		printf("%d,%d\n",edge,i);
	}
	printf("\nEdges required = %d\n",n-1);
}
