int partition (int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);
    int temp;
 
    for (int j = low; j <= high- 1; j++)
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

void mergeSort(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
 
void merge(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        merge(a, l, m);
        merge(a, m+1, r);
        mergeSort(a, l, m, r);
    }
}

void insertion(int a[], int n)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

void bubble(int a[],int n)
{
    int i,j,temp,flag=0;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag!=1)
            break;
    }
}

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