#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char* argv[])
{
	int i,j,m,n,k,l;
	char temp[5];
	clock_t t;
	double time;
	m=atoi(argv[1]);
	n=atoi(argv[2]);
	int a[m][n];
	t=clock();
	if(m%2==0)
		l=m/2;
	else
		l=m/2+1;
	for(k=0;k<l;k++)
	{
		for(i=k;i<m-k;i++)
		{
			for(j=k;j<n-k;j++)
			{		
				if(i==k || j==k || i==m-k-1 || j==n-k-1)
					a[i][j]=k;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	t=clock()-t;
	time=((double)t)/CLOCKS_PER_SEC;
	printf("\nTotal time taken = %lf sec\n",time);
	return 0;
}
