#include <stdio.h>

void main()
{
	int i,j,n;
	scanf("%d",&n);

	double a[n][2],b[n][2];	
	double adj[n][n];
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%lf",&adj[i][j]);

	for(i=0;i<n;i++)
	{
		a[i][0]=-2.0;
		a[i][1]=-2.0;
	}

	int start,max;
	scanf("%d",&start);

	a[start][0]=0.0;
	a[start][1]=-1.0;

	for(i=0;i<n;i++)
	{
		max=i;
		for(j=0;j<n;j++)
		{
			if(a[max][0] < a[j][0])
				max=j;
		}
		b[max][0]=a[max][0];
		b[max][1]=a[max][1];
		a[max][0]=-1.0;
		a[max][1]=-1.0;
		for(j=0;j<n;j++)
		{
			if(a[j][0]==-1.0d)
				continue;
			if(a[j][0] < adj[max][j]+b[max][0])
			{
				a[j][0]=adj[max][j]+b[max][0];
				a[j][1]=max;
			}				
		}
	}
	
	int end;
	scanf("%d",&end);
	printf("\nDistance : %.1lf\n",b[end][0]);
	for(i=0;i<=1;i--)
	{
		printf("%d <- ",end);
		if(b[end][1]==-1.0d)
		{
			break;
		}
		else
			end=b[end][1];
	}
	printf("\n");
}