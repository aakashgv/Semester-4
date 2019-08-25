#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,count=0,n,temp=0;
	char str[100];
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n;i++)
		if(str[i]=='X')
			temp++;
		else if(str[i]=='Y')
			count = temp + count;
	printf("\nNumber of substrings 'XY' is : %d\n",count);
	return 0;
}