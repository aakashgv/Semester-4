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

int queue[10],rear=-1,front=-1;
int visited[10],num,b[10][10];

int delete()
{
	int i,t;
	t=queue[0];
	if(rear>0)
	{
		for(i=0;i<=rear-1;i++)
			queue[i]=queue[i+1];
		rear--;
	}
	else
	{
		rear=front=-1;
	}
	return t;
}

void insert(int k)
{
	if(rear==-1)
		front++;
	rear++;
	queue[rear]=k;
}

void traverse(int s)
{
	int i;
	insert(s);
	visited[s]=1;

	while(rear!=-1)
	{
		s=delete();
		printf("\n%d",s+1);
		visited[s]=2;
		for(i=0;i<num;i++)
		{
			if(b[s][i]==1 && visited[i]==0)
			{
				insert(i);
				visited[i]=1;
			}
		}
	}
}

void bfs(int n,int a[][n],struct adjlist *v)
{
	int start,i,j;
	printf("\nEnter start vertex (max %d) :",n);
	scanf("%d",&start);
	for(i=0;i<n;i++)
		visited[i]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i][j]=a[i][j];
	num=n;
	printf("BFS Traversal : \n");
	traverse(start-1);
	printf("\n");
}