#include<stdio.h>

void main()
{
	int n,i,j;
	printf("Enter the number of elements:  ");
	scanf("%d",&n);
	int total[n],array[n],l[n],addition[n];
	for(i=0;i<n;i++){
		printf("Enter element:  ");
		scanf("%d",&array[i]);}
	addition[0]=array[0];
	total[0]=array[0];
	for(i=1;i<n;i++)
	{
		addition[i]=addition[i-1]+array[i];
		total[i]=total[i-1]+array[i];
		l[i]=0;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(addition[i] < total[i]-total[j])
			{
				addition[i]=total[i]-total[j];
				l[i]=j+1;
			}
		}
	}
	int max=0;
	for(i=1;i<n;i++)
	{
		if(addition[max] < addition[i])
			max=i;
	}
	for(i=0;i<n;i++)
	{
		if(addition[max]==addition[i])
		{
			printf("Maximum sum of subsequence : %d\n",addition[i]);
			printf("[%d:%d]\n",l[i],i);
		}
	}
}
