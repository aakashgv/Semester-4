#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

void add()
{
	deciconvert();
	int res = num1 + num2,base=2;
	if(c.b1 > c.b2)
		base=c.b1;
	else
		base=c.b2;
	convert(res,base);
	printf("%s(%d) + %s(%d) = %s(%d)\n",c.n1,c.b1,c.n2,c.b2,result,base);
}

void sub()
{
	deciconvert();
	int res = num1 - num2,base=2;
	if(c.b1 > c.b2)
		base=c.b1;
	else
		base=c.b2;
	convert(res,base);
	printf("%s(%d) - %s(%d) = %s(%d)\n",c.n1,c.b1,c.n2,c.b2,result,base);
}