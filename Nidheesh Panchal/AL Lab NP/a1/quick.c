int partition (int a[], int low, int high)
{
	int pivot = a[high];
	int i = (low - 1);
	int temp,j;
 
	for(j = low; j <= high- 1; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[high];
	a[high]=temp;
	return (i + 1);
}

void quick(int a[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(a, low, high);
		quick(a, low, pi - 1);
		quick(a, pi + 1, high);
	}
}
