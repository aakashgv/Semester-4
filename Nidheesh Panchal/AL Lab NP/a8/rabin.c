#include<stdio.h>
#include<string.h>

void rabin(char text[],char pat[])
{
	int n = strlen(pat);
	int m = strlen(text);
	int i, j;
	int p = 0;
	int t = 0;
	int h = 1;
	int q=101;
	int d=256;

	for (i = 0; i < n-1; i++)
		h = (h*d)%q;

	for (i = 0; i < n; i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + text[i])%q;
	}

	for (i = 0; i <= m - n; i++)
	{
		if ( p == t )
		{
			printf("\nSpurious hit");
			for (j = 0; j < n; j++)
				if (text[i+j] != pat[j])
					break;

			if (j == n)
				printf("\nPattern found at : %d \n", i);
		}

		if ( i < m-n )
		{
			t = (d*(t - text[i]*h) + text[i+n])%q;
			if (t < 0)
				t = (t + q);
		}
	}
}