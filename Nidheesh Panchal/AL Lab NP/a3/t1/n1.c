#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,cnt=0,n;
	char str[100];
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(str[i]=='X' && str[j]=='Y')
				++cnt;
	printf("\nNumber of substrings 'XY' is : %d\n",cnt);
	return 0;
}