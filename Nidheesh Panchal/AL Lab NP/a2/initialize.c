#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

int initializebase(FILE *f1,FILE *f2)
{
	rewind(f1);
	rewind(f2);
	char ch;
	int cnt=0;
	while((ch=fgetc(f1))!=EOF)
	{
		maxd[cnt++]=ch;
	}
	cnt--;
	while(fscanf(f2,"%s %d %s %d %s",c.op,&c.b1,c.n1,&c.b2,c.n2)!=EOF)
	{
		if(strcmp("add",c.op)==0)
			add();
		else
			sub();
	}
}