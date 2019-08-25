#include <stdio.h>

void main()
{
	double a[5],b[5];
	for(int i=0;i<5;i++)
	{
		a[i]=b[i]=i;
	}
	if(a[1]==b[1])
	{
		printf("hello");
	}
}