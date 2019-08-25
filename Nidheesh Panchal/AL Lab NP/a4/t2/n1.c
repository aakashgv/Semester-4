#include<stdio.h>
#include<string.h>

char txt[50],pat[25];
int lps[25],m,n;

void lpsa(int m)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < m)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = lps[len-1];
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
 
void kmp()
{
	m=strlen(pat);
	n=strlen(txt);
	int i;

	for(i=0;i<m;i++)
		if ((pat[i] >= 65) && (pat[i] <= 90))
			pat[i]=pat[i]+32;

	for(i=0;i<n;i++)
		if ((txt[i] >= 65) && (txt[i] <= 90))
			txt[i]=txt[i]+32;
 
	lpsa(m);
 
	i=0;
	int j=0;
	while (i < n)
	{
		if (pat[j] == txt[i])
		{
			j++;
			i++;
		}
 
		if (j == m)
		{
			printf("Found pattern at shift s = %d\n", i-j);
			j = lps[j-1];
		}
 
		else if (i < n && pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
}
 
void main()
{
	scanf("%s",txt);
	scanf("%s",pat);
	kmp();
}