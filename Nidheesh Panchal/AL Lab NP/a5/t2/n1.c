#include<stdio.h>
#include<string.h>

void main()
{
	char str1[]="abcbdab";
	char str2[]="bdcaba";
	int m=strlen(str1);
	int n=strlen(str2);
	int a[m+1][n+1];
	int i,j;
	for(i=0;i<m+1;i++)
		for(j=0;j<n+1;j++)
			a[i][j]=0;

	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			if(str1[i-1]==str2[j-1])
				a[i][j]=a[i-1][j-1]+1;

			else if(a[i-1][j]>=a[i][j-1])
				a[i][j]=a[i-1][j];

			else
				a[i][j]=a[i][j-1];
		}
	}
	for(i=0;i<m+1;i++)
	{
		for(j=0;j<n+1;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

	//print
	int k=-1;
	char b[m];
	i=m;
	j=n;
	while(i>0 && j>0)
	{
		if(str1[i-1]==str2[j-1])
		{
			b[++k]=str1[i-1];
			i--;
			j--;
		}

		else if(a[i][j]==a[i-1][j])
			i--;

		else if(a[i][j]==a[i][j-1])
			j--;
	}
	printf("\nlcs : ");
	k=strlen(b);
	for(i=k-1;i>=0;i--)
		printf("%c",b[i]);
	printf("\n");
}