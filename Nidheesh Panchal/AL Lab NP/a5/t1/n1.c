#include<stdio.h>
int n;
char ch='A';

printoptimal(int s[][n],int i,int j)
{
	if(i==j)
		printf("%c",ch++);
	else
	{
		printf("(");
		printoptimal(s,i,s[i][j]);
		printoptimal(s,s[i][j]+1,j);
		printf(")");
	}
}
void main()
{
	int i;
	scanf("%d",&n);
	int p[n+1],m[n][n],s[n][n];
	for(i=0;i<n+1;i++)
		scanf("%d",&p[i]);

	int l,j,k,q;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
			s[i][j]=0;
		}
	}

	for(l=1;l<n;l++)
	{
		for(i=0;i<n-l;i++)
		{
			j=i+l;
			m[i][j]=99999999;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]);
				if(q < m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}

	printoptimal(s,0,n-1);
	printf("\n");
}