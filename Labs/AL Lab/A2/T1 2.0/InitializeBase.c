#include"InitializeBase.h"
#include"add.h"

struct calculate
{
	char op[8],n1[32],n2[32];
	int base1,base2;
}calc;

char matrix[32],result[32];
int t;
int InitializeBase(FILE *f1,FILE *f2)
{
	rewind(f1);
	rewind(f2);
	char ch;
	int counter=0;
	while((ch=fgetc(f1))!=EOF)
	{
		matrix[counter++]=ch;
	}
	counter--;
	while(fscanf(f2,"%s %d %s %d %s",calc.op,&calc.base1,calc.n1,&calc.base2,calc.n2)!=EOF)
	{
		if(strcmp("add",calc.op)==0)
			{t=0;
			add(t);}
		else
			{t=1;
			add(t);}
	}
}

