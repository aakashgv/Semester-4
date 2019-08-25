#include"changebase.h"

int num1,num2;
char matrix[32],result[32];
void ChangeBase(int res,int base)
{
	char temp[32];
	int i=0,j=-1,n=0;
	for(i=0;i<32;i++)
		result[i]='\0';
	do
	{
		temp[n++]=matrix[res%base];
		res=res/base;
	}while(res >= base);
	temp[n]=matrix[res];
	for(i=n;i>=0;i--)
	{
		result[++j]=temp[i];
	}
}
