#include<stdio.h>
#include<string.h>

void fill(char pat[],int n,int lps[])
{
	int i,len=0;
	lps[0]=0;
	printf("\nn=%d\n",n);
	i=1;
	while(i<n)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

void kmp(char text[],char pat[])
{
	int m=strlen(text);
	int n=strlen(pat);

	int lps[n],i,j;

	fill(pat,n,lps);

	printf("\n");
	for(i=0;i<n;i++)
		printf("%c\t",pat[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",lps[i]);

	i=0;
	j=0;
	while(i<=m)
	{
		if(pat[j]==text[i])
		{
			i++;
			j++;
		}

		if(j==n)
		{
			printf("\nFound pattern at shift : %d\n",i-n);
			j=lps[j-1];
		}

		else if(pat[j]!=text[i])
		{
			if(j!=0)
			{
				printf("\n%d %d is the location of mismatch",i,j);
				j=lps[j-1];
			}
			else
				i++;
		}
	}
}