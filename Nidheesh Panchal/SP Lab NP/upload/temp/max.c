void max()
{
	int i,max;
	for(i=0;i<26;i++)
	{
		max=0;
		for(i=0;i<26;i++)
		{
			if(a[i]>a[max])
				max=i;
		}
		if(a[max]==0)
			break;
		printf("%c %d",max,a[max]);
		a[max]=0;
	}
}