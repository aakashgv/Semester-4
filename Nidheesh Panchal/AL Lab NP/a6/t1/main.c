#include<stdio.h>
#include<time.h>

void dynamic(int a[],int b[],int w,int n);
void greedy(int a[],int b[],int w,int n);

int a[5],b[5],w,n=5;

void main()
{
	clock_t t;
	double time;
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	scanf("%d",&w);

	t=clock();
	dynamic(a,b,w,n);
	t=clock()-t;
	time=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime taken for dynamic approach : %lf sec\n",time);

	t=clock();
	greedy(a,b,w,n);
	t=clock()-t;
	time=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime taken for greedy approach : %lf sec\n",time);
}