#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>
# define n 100000
void selection(int [],int);
void print(int [],int);
void bubble(int [],int);
void merge(int [],int,int);
void quick(int [],int,int);
void insertion(int [],int);

struct data
{
	int x;
};

int main(int argc,char **argv)
{
	int i,a[n];
	double time_taken;
	struct data d;
	FILE *fp;
	fp=fopen("test.dat","w+");
	clock_t t;

	srand(time(0));
	for(i=0;i<n;i++)
	{
		d.x=rand()%n+1;
		fprintf(fp,"%d\n",d.x);
	}
	
	rewind(fp);
	i=-1;
	while(fscanf(fp,"%d",&d.x)!=EOF)
	{
		a[++i]=d.x;
	}

	t=clock();

	selection(a,n);

	t=clock()-t;
	time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for selection = %lf",time_taken);

	rewind(fp);
	i=-1;
	while(fscanf(fp,"%d",&d.x)!=EOF)
	{
		a[++i]=d.x;
	}
	t=clock();

	bubble(a,n);

	t=clock()-t;
	time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for bubble = %lf",time_taken);

	rewind(fp);
	i=-1;
	while(fscanf(fp,"%d",&d.x)!=EOF)
	{
		a[++i]=d.x;
	}
	
	t=clock();

	insertion(a,n);

	t=clock()-t;
	time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for insertion = %lf",time_taken);

	rewind(fp);
	i=-1;
	while(fscanf(fp,"%d",&d.x)!=EOF)
	{
		a[++i]=d.x;
		//printf("%d",a[i]);
	}
	
	t=clock();

	merge(a,0,n-1);

	t=clock()-t;
	time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for merge = %lf",time_taken);

	rewind(fp);
	i=-1;
	while(fscanf(fp,"%d",&d.x)!=EOF)
	{
		a[++i]=d.x;
	}
	
	t=clock();

	quick(a,0,n-1);

	t=clock()-t;
	time_taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime required for quick = %lf\n",time_taken);

	fclose(fp);

	return 0;
}