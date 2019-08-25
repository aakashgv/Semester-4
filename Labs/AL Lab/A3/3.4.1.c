#include<stdio.h>
#include<math.h>
# define n 8

int a[n][n],asum[n],maxsum,min1,min2,sumc;

void arraysum()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		asum[i]=0;
		for(j=0;j<n;j++)
			asum[i]=asum[i]+a[j][i];
	}
}

void sum(int j)
{
	int i;
	sumc=0;
	for(i=0;i<n;i++)
		sumc+=a[i][j];
}

void max()
{
	int i;
	maxsum=0;
	for(i=0;i<n;i++)
	{
		if(asum[maxsum] > asum[i])
			maxsum=i;
	}
	for(i=0;i<n;i++)
	{
		if(asum[maxsum] < asum[i] && asum[i]!=0)
			maxsum=i;
	}
}

void minimum(int j)
{
	min1=min2=0;
	int i;
	
	for(i=0;i<n;i++)
	{
		if(a[min2][j] < a[i][j])
			min2=i;
	}

	for(i=0;i<n;i++)
	{
		if(a[min1][j] > a[i][j])
			min1=i;
	}
	for(i=0;i<n;i++)
	{
		if(a[min2][j] > a[i][j] && a[i][j] != a[min1][j] && i!=min1)
			min2=i;
	}
}

void multiply(int i,int times)
{
	int j,k,temp=a[i][maxsum];
	for(k=0;k<n;k++)
	{
		if(temp==a[k][maxsum])
		{
			for(j=0;j<n;j++)
				a[k][j] = a[k][j]*(int)pow(2,times);
		}
	}
}

void subtract(int j,int diff)
{
	int i;
	for(i=0;i<n;i++)
		a[i][j]=a[i][j]-diff;
}

void main()
{
	int i,j,k,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	for(k=0;k<n;k++)
	{
		arraysum();
		max();
		minimum(maxsum);
		sumc=asum[maxsum];
		while(sumc!=0)
		{
			arraysum();
			minimum(maxsum);
			sumc=asum[maxsum];
			if(a[min1][maxsum]==a[min2][maxsum])
			{
				subtract(maxsum,a[min1][maxsum]);
				continue;
			}
			i=1;
			while(a[min1][maxsum]*(int)pow(2,i) <= a[min2][maxsum])
			{
				i++;
			}
			i--;
			if(i>=1)
			{
				multiply(min1,i);
			}				

			temp=a[min2][maxsum]-(a[min1][maxsum]-1);
			if(temp==1)
				continue;
			i=1;
			while((int)pow(2,i) < temp)
			{
				i++;
			}
			temp=(int)pow(2,i)-temp;
			temp=(a[min1][maxsum]-1)-temp;
			subtract(maxsum,temp);

			arraysum();
			sumc=asum[maxsum];
		}
	}
	printf("\n\nResultant matrix :\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}	
}