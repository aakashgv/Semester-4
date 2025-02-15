#include<stdio.h>
#include<string.h>

int max(int i, int j)
{
	return i>j ? i : j;
}

int lcs( char x[], char y[], char z[], int m,int n, int o)
{
	int L[m+1][n+1][o+1],i,j,k;

	for (i=0; i<=m; i++)
	{
		for (j=0; j<=n; j++)
		{
			for (k=0; k<=o; k++)
			{
				if (i == 0 || j == 0|| k==0)
					L[i][j][k] = 0;

				else if (x[i-1] == y[j-1] && x[i-1]==z[k-1])
					L[i][j][k] = L[i-1][j-1][k-1] + 1;

				else
					L[i][j][k] = max(max(L[i-1][j][k],L[i][j-1][k]),L[i][j][k-1]);
			}
		}
	}

	//print lcs
	
	int p=-1;
	char str[L[m][n][o]+1];
	int temp[6],q,max=0;

	i=m;
	j=n;
	k=o;
	while(i>0 || j>0 || k>0)
	{
		if(x[i]==y[j] && x[i]==z[k])
		{
			str[++p]=x[i];
			i--;
			j--;
			k--;
		}
		else
		{
			temp[0]=L[i][j][k-1];
			temp[1]=L[i][j-1][k];
			temp[2]=L[i][j-1][k-1];
			temp[3]=L[i-1][j][k];
			temp[4]=L[i-1][j][k-1];
			temp[5]=L[i-1][j-1][k];
			for(q=0;q<6;q++)
			{
				if(temp[max]<temp[q])
					max=q;
			}
			switch(max)
			{
				case 0:
					k--;
					break;
				case 1:
					j--;
					break;
				case 2:
					j--;
					k--;
					break;
				case 3:
					i--;
					break;
				case 4:
					i--;
					k--;
					break;
				case 5:
					i--;
					j--;
					break;
			}
		}
	}

	for(i=L[m][n][o]+1;i>=0;i--)
		printf("%c",str[i]);
	
	return L[m][n][o];
}