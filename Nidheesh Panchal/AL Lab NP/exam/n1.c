#include<stdio.h>

int n=15,a[15];

void flip(int k)
{
	int i,b[n],j=k-1;
	for(i=k;i<n;i++)
		b[i]=a[i];
	for(i=n-1;i>=k;i--)
		a[++j]=b[i];
}

int checkorder()
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1])
			return 0;
	}
	return 1;
}

void main()
{
	int i,max=0,order=1,min=0,j;
	FILE *f;
	for(i=0;i<15;i++)
		a[i]=0;
	f=fopen("input.txt","r");
	i=0;
	while(fscanf(f,"%d",&a[i])!=EOF)
	{
		i++;
	}
	for(i=0;i<15;i++)
	{
		if(a[i]==0)
		{
			n=i;
			break;
		}
	}
	flip(0);
	//for(i=0;i<n;i++)
	//	printf("\n%d",a[i]);
	for(j=0;j<n-1;j++)
	{
		max=j;
		for(i=j;i<n;i++)
			if(a[max] < a[i])
				max=i;

		if(max!=n-1)
		{
			flip(max);
			printf("%d ",max+1);
		}
		
		flip(j);
		printf("%d ",j+1);
		if(checkorder()==1)
		{
			printf("0\n");
			break;			
		}
	}
	//for(i=0;i<n;i++)
	//	printf("\n%d",a[i]);
}