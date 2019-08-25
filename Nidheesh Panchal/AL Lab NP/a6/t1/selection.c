void selection(float frac[],int a[],int b[],int n)
{
	int i,j,small;
	float temp;
	for(i=0;i<n-1;i++)
	{
		small=i;
		for(j=i;j<n;j++)
			if(frac[small] < frac[j])
				small=j;
		if(small!=i)
		{
			temp=frac[small];
			frac[small]=frac[i];
			frac[i]=temp;

			temp=a[small];
			a[small]=a[i];
			a[i]=temp;

			temp=b[small];
			b[small]=b[i];
			b[i]=temp;
		}
	}
}			
