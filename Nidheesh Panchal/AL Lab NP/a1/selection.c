void selection(int a[],int n)
{
	int i,j,small,temp;
	for(i=0;i<n-1;i++)
	{
		small=i;
		for(j=i;j<n;j++)
			if(a[small] > a[j])
				small=j;
		if(small!=i)
		{
			temp=a[small];
			a[small]=a[i];
			a[i]=temp;
		}
	}
}			
