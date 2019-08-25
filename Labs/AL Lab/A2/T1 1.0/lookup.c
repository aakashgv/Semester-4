#include"lookup.h"

int num1,num2;
char matrix[32],result[32];


int lookup(char ch)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(ch==matrix[i])
			return i;
	}
}
