#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[100],line[100],namtab[25],argtab[25][25],deftab[100][25];
int numarg,macro=0;
int point;



void printmacro()
{
	int i=0,j,k,l;
	char temp;
	int arg,flag=0;
	char word[20];
	while(line[i]!=' ')
		i++;
	i++;
	j=-1;
	k=-1;
	while(line[i]!='\0')
	{
		if(line[i]==',')
		{
			strcpy(argtab[++k],word);
			j=-1;
			i++;
		}
		else
		{
			word[++j]=line[i];
			i++;
		}
	}
	strcpy(argtab[++k],word);

	for(i=0;deftab[i][0]!='\0';i++)
	{
		flag=0;
		for(j=0;deftab[i][j]!='\0';j++)
		{
			if(deftab[i][j]==37)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			for(j=0;deftab[i][j]!='\0';j++)
			{
				if(deftab[i][j]==37)
				{
					temp=deftab[i][++j];
					l=temp-'0';
					printf("%s",argtab[l-1]);
					continue;
				}
				else
					printf("%c",deftab[i][j]);
			}
		}
		else
			printf("%s",deftab[i]);
	}
}

void main()
{
	int i,j,l=-1,n;
	char word[20];
	FILE* f;
	f=fopen("input.asm","r");

	//reading the NASM file
	while(fgets(line,sizeof(line),f)!=NULL)
	{
		//ignoring the spaces before the text
		/*for(i=0;line[i]!='\0';i++)
		{
			if(line[i]==' ')
			{
				printf("%c",line[i]);
				continue;
			}
			else
				break;
		}*/
		if(line[0]=='%' && line[1]=='m')
		{
			j=-1;
			for(i=7;line[i]!=' ';i++)
			{
				namtab[++j]=line[i];
			}
			numarg=line[i+1];
			macro=1;
		}

		else if(macro==1)
		{			
			char word[25];
			/*for(m=0;line[m]!=' ' && line[m]!='\0';m++)
			{
				word[++n]=line[m];
			}*/
			if(line[0]=='e' && line[1]=='n')
			{
				macro=0;
			}
			if(macro!=0)
				strcpy(deftab[++l],line);
		}

		else
		{
			j=-1;
			for(i=0;line[i]!=' ';i++)
				word[++j]=line[i];
			if(namtab[0]==line[0] && namtab[1]==line[1])
			{
				printmacro();
			}
			else
				printf("%s",line);
		}
		//point=ftell(f);
		//printf("\n");
	}
}