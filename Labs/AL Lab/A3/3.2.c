#include<stdio.h>
#include<string.h>

char text[50],pattern[25];
int l[25],m,n;

void longest(int m)
{
	int length1 = 0;
	l[0] = 0;
	int i = 1;
	while (i < m)
	{
		if (pattern[i] == pattern[length1])
		{
			length1++;
			l[i] = length1;
			i++;
		}
		else
		{
			if (length1 != 0)
				length1 = l[length1-1];
			else // if (length1 == 0)
			{
				l[i] = 0;
				i++;
			}
		}
	}
}
 
void algo()
{
	m=strlen(pattern);
	n=strlen(text);
	int i;

	for(i=0;i<m;i++)
		if ((pattern[i] >= 65) && (pattern[i] <= 90))
			pattern[i]=pattern[i]+32;

	for(i=0;i<n;i++)
		if ((text[i] >= 65) && (text[i] <= 90))
			text[i]=text[i]+32;
 
	longest(m);
 
	i=0;
	int j=0;
	while (i < n)
	{
		if (pattern[j] == text[i])
		{
			j++;
			i++;
		}
 
		if (j == m)
		{
			printf("Found pattern at shift s = %d\n", i-j);
			j = l[j-1];
		}
 
		else if (i < n && pattern[j] != text[i])
		{
			if (j != 0)
				j = l[j-1];
			else
				i = i+1;
		}
	}
}
 
void main()
{
	printf("Enter text:  ");
	scanf("%s",text);
	printf("Enter pattern:  ");
	scanf("%s",pattern);
	algo();
}
