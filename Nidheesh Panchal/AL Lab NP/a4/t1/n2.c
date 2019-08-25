#include<stdio.h>
#include<math.h>
# define n 5

unsigned long long int max=0,min=0,sumc=0,col;
unsigned long long int a[n][n];

void maximum(int j)
{
	int i;
	max=0;
	for(i=0;i<n;i++)
	{
		if(a[i][j] > a[max][j])
			max=i;
	}
}

void takecolumn()
{
	int i,j;
	col=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j] > a[i][col])
				col=j;
}

void maxsum()
{
	int i,j,sum=0,temp=0;
	col=0;

	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			sum+=a[j][i];
		}
		if(temp < sum)
		{
			temp=sum;
			col=i;
		}
	}
}

void minimum(int j)
{
	min=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i][j] < a[min][j])
			min=i;
	}
}

void colsum(int j)
{
	int i;
	sumc=0;
	for(i=0;i<n;i++)
	{
		if(a[i][j]!=0)
			sumc=1;
	}
	for(i=0;i<n;i++)
	{
		if(sumc!=0 && a[i][j]==0)
			a[i][j]=1;
	}
}

void multiply(int i,int pro)
{
	int j;
	for(j=0;j<n;j++)
	{
		a[i][j]*=pow(2,pro);
	}
}

void subtract(int j, int dif)
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i][j]-=dif;
	}
}

void mul(int j)
{
	int i,l;
	for(i=0;i<n;i++)
	{
		l=1;
		while(a[i][j]*((int)pow(2,l)) <= a[max][j])
		{
			l++;
		}
		l--;
		if(l>=1)
			multiply(i,l);
	}
}

void suball()
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		minimum(k);
		if(a[min][k] > 1)
		{
			subtract(k,-(1-a[min][k]));
		}
	}
}

void main()
{
	int i,j,k;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%llu",&a[i][j]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%llu ",a[i][j]);
		}
		printf("\n");
	}
		
	for(k=0;k<n;k++)
	{
		sumc=1;
		takecolumn();
		//maxsum();
		while(sumc!=0)
		{
			colsum(col);
			maximum(col);
			mul(col);
			minimum(col);
			if(a[max][col]==a[min][col])
				subtract(col,a[min][col]);
			else
				subtract(col,-(1-a[min][col]));
			colsum(col);
			suball();
		}
		//suball();		
	}

	printf("\nResultant matrix :\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%llu ",a[i][j]);
		}
		printf("\n");
	}
}