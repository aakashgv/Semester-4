#include<stdio.h>
#include<string.h>

int nchar=256;

int nstate(char pat[], int n, int state, int x)
{
	if (state < n && x == pat[state])
		return state+1;

	int ns, i;

	for (ns = state; ns > 0; ns--)
	{
		if (pat[ns-1] == x)
		{
			for (i = 0; i < ns-1; i++)
				if (pat[i] != pat[state-ns+1+i])
					break;
			if (i == ns-1)
				return ns;
		}
	}
	return 0;
}

void tf(char pat[], int n, int t[][nchar])
{
	int state, x;
	printf("\n");
	for (state = 0; state <= n; ++state)
	{
		for (x = 0; x < nchar; ++x)
		{
			t[state][x] = nstate(pat, n, state, x);
			if(t[state][x]!=0)
				printf("%d ",t[state][x]);
		}
		printf("\n");
	}		
}

void fin(char text[], char pat[])
{
	int n = strlen(pat);
	int m = strlen(text);

	int t[n+1][nchar];

	tf(pat, n, t);

	int i, state=0;
	for (i = 0; i < m; i++)
	{
		printf("\n%d -> ",state);
		state = t[state][text[i]];
		printf("%d",state);
		if (state == n)
			printf ("\nPattern found at index : %d\n",i-n+1);
	}
}