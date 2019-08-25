#include<stdio.h>
void selection(float [],int [],int [],int n);

void greedy(int a[],int b[],int w,int n)
{
	float frac[n];
	int value=0,i;
	for(i=0;i<n;i++)
		frac[i]=b[i]/a[i];

	selection(frac,a,b,n);

	printf("\nItem selected :\n");
	for(i=0;i<n && w>=0;i++)
	{
		if(a[i]<=w)
		{
			printf("%d\n",i+1);
			value+=b[i];
			w=w-a[i];
		}
	}
	printf("\nvalue = %d\n",value);
}