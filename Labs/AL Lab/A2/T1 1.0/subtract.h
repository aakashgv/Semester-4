#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<sys/time.h>

struct calculate
{
	char op[8],n1[32],n2[32];
	int base1,base2;
}calc;
int num1,num2;

struct timeval tv;
long time_start, time_end;


void subtract();
