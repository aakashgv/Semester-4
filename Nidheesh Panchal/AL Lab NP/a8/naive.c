#include<stdio.h>
#include<string.h>

void naive(char text[],char pat[])
{
	int m=strlen(text);
	int n=strlen(pat);
	int i,j,flag,temp=0;

	for(i=0;i<=m-n;)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(text[i]==pat[j])
				i++;
			else
			{
				flag=1;
				i++;
				break;
			}
		}
		if(flag==0)
		{
			temp=1;
			printf("\nPattern found at shift : %d\n",i-n);
		}
	}
	if(temp==0)
		printf("\nNo pattern found");
}