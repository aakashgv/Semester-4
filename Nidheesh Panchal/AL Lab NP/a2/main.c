#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>

int initializebase(FILE *f1,FILE *f2);
void add();
void sub();
void deciconvert();
void convert(int,int);
int check(char);

int num1,num2;
char maxd[32],result[32];

struct calc
{
	char op[8],n1[32],n2[32];
	int b1,b2;
}c;

int main()
{
	FILE *f1,*f2;
	f1=fopen("test1.txt","r");
	f2=fopen("test2.dat","r");
	initializebase(f1,f2);
	return 0;	
}

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
	int res,base=2,flag=0;
	if(num1>=num2)
		res=num1-num2;
	else
	{
		res=num2-num1;
		flag=1;
	}
	if(c.b1 > c.b2)
		base=c.b1;
	else
		base=c.b2;
	convert(res,base);
	if(flag==1)
		printf("%s(%d) - %s(%d) = -%s(%d)\n",c.n1,c.b1,c.n2,c.b2,result,base);
	else
		printf("%s(%d) - %s(%d) = %s(%d)\n",c.n1,c.b1,c.n2,c.b2,result,base);
}

void deciconvert()
{
	int i,sum=0,j=0,temp;
	char ch[32];
	int n=strlen(c.n1);
	for(i=n-1;i>=0;i--)
	{
		temp=check(c.n1[i]);
		sum = sum + ((int)pow(c.b1,j) * temp);
		j++;
	}
	num1=sum;
	n=strlen(c.n2);
	j=0;
	sum=0;
	for(i=n-1;i>=0;i--)
	{
		temp=check(c.n2[i]);
		sum = sum + ((int)pow(c.b2,j) * temp);
		j++;
	}
	num2=sum;
}

void convert(int res,int base)
{
	char temp[32];
	int i=0,j=-1,n=0;
	for(i=0;i<32;i++)
		result[i]='\0';
	do
	{
		temp[n++]=maxd[res%base];
		res=res/base;
	}while(res >= base);
	temp[n]=maxd[res];
	for(i=n;i>=0;i--)
	{
		result[++j]=temp[i];
	}
}

int check(char ch)
{
	int i;
	for(i=0;i<32;i++)
	{
		if(ch==maxd[i])
			return i;
	}
}
