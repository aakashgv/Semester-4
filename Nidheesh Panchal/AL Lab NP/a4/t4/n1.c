#include<stdio.h>

void main()
{
	int n,i,j;
	scanf("%d",&n);
	int tot[n],a[n],l[n],sum[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sum[0]=a[0];
	tot[0]=a[0];
	for(i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		tot[i]=tot[i-1]+a[i];
		l[i]=0;
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(sum[i] < tot[i]-tot[j])
			{
				sum[i]=tot[i]-tot[j];
				l[i]=j+1;
			}
		}
	}
	int max=0;
	for(i=1;i<n;i++)
	{
		if(sum[max] < sum[i])
			max=i;
	}
	for(i=0;i<n;i++)
	{
		if(sum[max]==sum[i])
		{
			printf("Maximum sum of subsequence : %d\n",sum[i]);
			printf("[%d:%d]\n",l[i],i);
		}
	}
}