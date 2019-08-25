#include<stdio.h>

struct adjlist
{
	int color;
	int vertex;
	struct adjlist *adj;
	struct node *edge;
};

struct node
{
	int vertex;
	struct node *link;
};

int visited[10],num,b[10][10],d[10],k,rem;

void traverse(int s)
{
	int i;
	d[++k]=s+1;
	visited[s]=1;
	for(i=0;i<num;i++)
		if(b[s][i]==1 && visited[i]==0 && i!=rem)
			traverse(i);
}

int check()
{
	int i;
	for(i=0;i<num;i++)
	{
		if(d[i]==0)
			break;
	}
	if(i<num-1)
		return 1;
	return 0;
}

void arti(int n,int a[][n],struct adjlist *v)
{
	int start,i,j,flag=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i][j]=a[i][j];
	num=n;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			d[j]=0;
			visited[j]=0;
		}
		k=-1;
		rem=i;
		if(i==0)
			traverse(1);
		else
			traverse(0);
		if(check())
		{
			flag=1;
			printf("\nArticulation point : %d",i+1);
		}
	}
	if(flag==0)
		printf("\nNo articulation point");	
	printf("\n");
}