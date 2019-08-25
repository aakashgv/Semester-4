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

int visited[10],num,b[10][10];

void traverse(int s)
{
	int i;
	printf("\n%d",s+1);
	visited[s]=1;
	for(i=0;i<num;i++)
		if(b[s][i]==1 && visited[i]==0)
			traverse(i);
}

void dfs(int n,int a[][n],struct adjlist *v)
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
	printf("DFS Traversal : \n");
	traverse(start-1);
	printf("\n");
}
