#include<stdio.h>

void dynamic(int a[],int b[],int w,int n)
{
	int i,j;
	int c[n+1][w+1];

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<w+1;j++)
		{
			if(i==0 || j==0)
				c[i][j]=0;

			else if(a[i-1] > j)
				c[i][j]=c[i-1][j];

			else if(a[i-1]<=j)
			{
				if(c[i-1][j] > c[i-1][j-a[i-1]]+b[i-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i-1][j-a[i-1]]+b[i-1];
			}
		}
	}

	i=n;
	j=w;
	printf("\nitems selected :\n");
	while(i!=0)
	{
		if(c[i-1][j]==c[i][j])
			i--;
		else
		{
			printf("%d\n",i);
			i--;
			j=w-a[i-1];
		}
	}
	printf("Maximum value = %d\n",c[n][w]);
}