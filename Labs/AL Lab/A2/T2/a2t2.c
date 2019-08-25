#include<stdio.h>

void main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n];

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int l[n],max;

	for(i=0;i<n;i++)
		l[i]=1;

	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[i]>a[j] && l[i]<l[j]+1)
				l[i]=l[j]+1;

	max=l[0];

	for(i=1;i<n;i++)
		if(max < l[i])
			max=l[i];

	printf("\nLongest monotone increasing subsequence is : %d\n",max);

	
	printf("\n");
}
