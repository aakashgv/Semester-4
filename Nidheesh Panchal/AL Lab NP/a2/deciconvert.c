#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

void deciconvert()
{
	int i,sum=0,j=0,temp;
	char ch[32];
	int n=strlen(c.n1);
	for(i=n-1;i>=0;i--)
	{
		temp=check(c.n1[i]);
		sum = sum + ((int)pow(c.b1,j) * temp);
		j++;
	}
	num1=sum;
	n=strlen(c.n2);
	j=0;
	sum=0;
	for(i=n-1;i>=0;i--)
	{
		temp=check(c.n2[i]);
		sum = sum + ((int)pow(c.b2,j) * temp);
		j++;
	}
	num2=sum;
}