#include"add.h"
#include"changebase.h"
#include"lookup.h"
#include"subtract.h"

int num1,num2;
char matrix[32],result[32];
struct timeval tv;
long time_start, time_end;
void add(int t)
{
	if (t==1){subtract();}	
	gettimeofday(&tv,NULL);
	time_start = (tv.tv_sec *1e+6) + tv.tv_usec;

	
	int i,sum=0,j=0,temp;
	char ch[32];
	int n=strlen(calc.n1);
	for(i=n-1;i>=0;i--)
	{
		temp=lookup(calc.n1[i]);
		sum = sum + ((int)pow(calc.base1,j) * temp);
		j++;
	}
	num1=sum;
	n=strlen(calc.n2);
	j=0;
	sum=0;


	for(i=n-1;i>=0;i--)
	{
		temp=lookup(calc.n2[i]);
		sum = sum + ((int)pow(calc.base2,j) * temp);
		j++;
	}
	num2=sum;
	int res = num1 + num2,base=2;
	if(calc.base1 > calc.base2)
		base=calc.base1;
	else
		base=calc.base2;
	ChangeBase(res,base);

	gettimeofday (&tv, NULL);
	time_end = (tv.tv_sec *1e+6) + tv.tv_usec;
	long time= time_end-time_start;
	printf("\n Time= %ld \n", time);

	printf("%s(%d) + %s(%d) = %s(%d)\n",calc.n1,calc.base1,calc.n2,calc.base2,result,base);
}
