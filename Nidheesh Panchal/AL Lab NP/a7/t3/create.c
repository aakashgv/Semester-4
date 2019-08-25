#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int m,n;

//n=number of vertices

/*
color
-1 = unvisited
0 = visited
1 = visited all neighbours
*/

struct adjlist
{
	int color;
	int vertex;
	struct adjlist *adj;
	struct node *edge;
}*v;

struct node
{
	int vertex;
	struct node *link;
}*e;

void createlist(int a[][n])
{
	int i,j;
	struct adjlist *curr;
	struct node *temp;
	curr=v;
	temp=e;
	for(i=n-1;i>=0;i--)
	{
		e=NULL;
		curr=(struct adjlist*)malloc(sizeof(struct adjlist));
		curr->adj=NULL;
		curr->vertex=i+1;
		curr->color=-1;
		curr->edge=NULL;
		for(j=n-1;j>=0;j--)
		{
			if(a[i][j]==1)
			{
				temp=(struct node*)malloc(sizeof(struct node));
				temp->link=NULL;
				temp->vertex=j+1;
				if(e==NULL)
					e=temp;
				else
				{
					temp->link=e;
					e=temp;
				}
			}			
		}
		if(v==NULL)
		{
			curr->edge=e;
			v=curr;
		}
		else
		{
			curr->edge=e;
			curr->adj=v;
			v=curr;
		}

	}
}

void initmat(int a[][n])
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
}

void createmat(int a[][n])
{
	int i,j,x;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>i)
			{
				x=rand()%2;
				a[i][j]=x;
				a[j][i]=x;
			}				
		}
	}
}

void print()
{
	struct adjlist *curr;
	struct node *temp;
	curr=v;
	while(curr!=NULL)
	{
		printf("\n%d",curr->vertex);
		temp=curr->edge;
		while(temp!=NULL)
		{
			printf(" -> %d",temp->vertex);
			temp=temp->link;
		}
		curr=curr->adj;
	}
}

void arti(int,int [][n],struct adjlist*);

void main()
{
	int i,j;
	v=NULL;
	e=NULL;
	srand(time(0));
	n=rand()%10;
	int a[n][n];
	initmat(a);
	createmat(a);
	createlist(a);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	print();
	printf("\n");

	arti(n,a,v);
}
