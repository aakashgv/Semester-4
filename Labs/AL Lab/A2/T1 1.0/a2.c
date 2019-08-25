#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<sys/time.h>
#include"InitializeBase.h"
#include"add.h"
#include"subtract.h"
#include"lookup.h"
#include"changebase.h"


void add();
void subtract();
void ChangeBase(int,int);
int lookup(char);
struct timeval tv;
long time_start, time_end;

int num1,num2;
char matrix[32],result[32];



int main()
{
	FILE *f1,*f2;
	f1=fopen("File1.txt","r");
	f2=fopen("File2.dat","r");
	InitializeBase(f1,f2);
	return 0;	
}







