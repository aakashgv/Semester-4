#include <stdio.h>

void main()
{
	int i,j,n;
	scanf("%d",&n);
	int a[n][n],min;
	int t[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&t[i]);
	}
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(t[min]<t[j])
				min=j;
		}
		int temp=t[min];
		t[min]=t[i];
		t[i]=temp;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			a[i][j]=0;
	}

	int d;
	scanf("%d",&d);

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(t[j]+t[i]<=9 && a[i][j-1]==0)
				a[i][j]=t[i]+t[j];

			else if(a[i][j-1]!=0)
			{
				if(a[i][j-1]+t[j]<=9)
					a[i][j]=a[i][j-1]+t[j];
				else
					a[i][j]=a[i][j-1];
			}
		}
	}

	int flag=0;
	
	for(i=0;i<n;i++)
	{
		if(t[i]==d)
		{
			printf("\n%d",t[i]);
			flag=1;
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<n;i++)
	{
		if(a[i][n-1]==9)
		{
			flag=1;
			for(j=n-1;j>0;j--)
			{
				if(a[i][j]!=a[i][j-1])
				{
					printf("%d,",t[j]);
				}
			}
			printf("%d",t[i]);
			printf("\n");
		}
	}

	if(flag==0)
	{
		printf("\nNo subset found\n");
	}
}