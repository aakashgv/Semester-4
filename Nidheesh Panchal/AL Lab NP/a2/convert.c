#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

void convert(int res,int base)
{
	char temp[32];
	int i=0,j=-1,n=0;
	for(i=0;i<32;i++)
		result[i]='\0';
	do
	{
		temp[n++]=maxd[res%base];
		res=res/base;
	}while(res > base);
	temp[n]=maxd[res];
	for(i=n;i>=0;i--)
	{
		result[++j]=temp[i];
	}
}

int check(char ch)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(ch==maxd[i])
			return i;
	}
}