#include <stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}

void main()
{
	int n;
	scanf("%d",&n);
	int t[n];
	
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);

	int d,sum=0;
	scanf("%d",&d);

	int a[n+1][d+1];

	for(i=0;i<=n;i++)
		a[i][0]=0;
	for(i=0;i<d+1;i++)
		a[0][i]=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<d+1;j++)
		{
			if(j < t[i-1])
				a[i][j]=a[i-1][j];

			else
				a[i][j]=max(a[i-1][j],a[i-1][j-t[i-1]]+t[i-1]);
		}
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<d+1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	int flag=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<d+1;j++)
		{
			if(a[i][j]==9)
				flag=1;
		}
	}

	if(flag==1)
	{
		i=n;
		j=d;
		while(i>=0)
		{
			while(j>=0)
			{
				if(a[i][j]==a[i][j-1])
					i--;
				else
				{
					i--;
					j=j-t[i-1];
					printf("\n%d\n",t[i-1]);
				}
			}
		}

	}
	else
		printf("\nNot possible");
}