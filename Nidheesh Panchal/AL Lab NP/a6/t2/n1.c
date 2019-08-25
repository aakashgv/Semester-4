#include<stdio.h>
#include<string.h>

int lcs( char x[], char y[], char z[], int m,int n, int o);

int main()
{
	char x[] = "hellw";
	char y[] = "hellohellworld";
	char z[] = "hellwithit";

	int m = strlen(x);
	int n = strlen(y);
	int o = strlen(z);

	printf("\nLength of LCS is %d\n\n",lcs(x, y,z, m, n, o));

	return 0;
}
