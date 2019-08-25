#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int level=0,lineno=0,nameno=0,n=1;

//stack will store the argument table for each expansion
struct stack
{
	struct argument *front;
	struct stack *link;
};

//argument table
struct argument
{
	char value1[50],value2[50];
	struct argument *link1,*link2;
};

//definition table
struct definition
{
	char string[100];
	struct definition *link1,*link2;
};

//name table
struct nametab
{
	char name[25];
	int start,end;
	struct nametab *link1,*link2;
};

//initializing all the pointers
struct stack *top=NULL;
struct argument *frontarg=NULL,*reararg=NULL;
struct definition *frontdef=NULL,*reardef=NULL;
struct nametab *frontnam=NULL,*rearnam=NULL;

//function to push argument in the table
void pusha(char str[])
{
	struct argument *temp=(struct argument *)malloc(sizeof(struct argument));
	strcpy(temp->value1 , str);
	strcpy(temp->value2 , str);
	if(frontarg == NULL)
	{
		temp->link1=NULL;
		temp->link2==NULL;
		frontarg=temp;
		reararg=temp;
	}
	else
	{
		reararg->link1 = temp;
		temp->link1=NULL;
		temp->link2=reararg;
		reararg=temp;
	}
}

//funtion to push definition in the table
void pushd(char str[])
{
	struct definition *temp=(struct definition *)malloc(sizeof(struct definition));
	strcpy(temp->string , str);
	if(frontdef == NULL)
	{
		temp->link1=NULL;
		temp->link2=NULL;
		frontdef=temp;
		reardef=temp;
	}
	else
	{
		reardef->link1 = temp;
		temp->link1 = NULL;
		temp->link2 = reardef;
		reardef=temp;
	}
}

//funtion to push name in the table
void pushn(char str[],int s)
{
	struct nametab *temp=(struct nametab *)malloc(sizeof(struct nametab));
	strcpy(temp->name , str);
	if(frontnam == NULL)
	{
		temp->start=s;
		temp->end=0;
		temp->link1=NULL;
		temp->link2=NULL;
		frontnam=temp;
		rearnam=temp;
	}
	else
	{
		rearnam->link1 = temp;
		temp->start=s;
		temp->end=0;
		temp->link1 = NULL;
		temp->link2 = rearnam;
		rearnam=temp;
	}
}

//funtion to push argument onto to stack for future use
void push()
{
	struct stack *node=(struct stack *)malloc(sizeof(struct stack));
	node->front=frontarg;
	node->link=NULL;
	if(top==NULL)
		top=node;
	else
	{
		node->link=top;
		top=node;
	}
}

//pop argument from the stack so as to expand further
void pop()
{
	struct stack *node=(struct stack *)malloc(sizeof(struct stack));
	node=top;
	top=top->link;
	if(top!=NULL)
		frontarg=top->front;
	free(node);
}

//to enter the end line for a macro
void endnam()
{
	//printf("%d",level);
	struct nametab *temp=(struct nametab *)malloc(sizeof(struct nametab));
	temp=frontnam;
	int i=1;
	if(level!=1)
	{
		while(i!=level)
		{
			temp=temp->link1;
			i++;
		}
		temp->end=lineno;
	}
	else if(level==1)
	{
		while(temp->end!=0)
		{
			temp=temp->link1;
		}
		temp->end=lineno;
	}
}

//to create definition table by processing it
void define(char line[])
{
	if(line[0]==';')
		return;
	lineno++;
	pushd(line);
	int i,j=-1;
	char word[25],temp[25];
	for(i=0;line[i]!=' ' && line[i]!='\0';i++)
		word[++j]=line[i];
	word[++j]='\0';
	if(line[0]==37 && line[2]=='e')
	{
		endnam();
		level--;
	}
	else if(strcmp(word,"%macro")==0)
	{
		level++;
		j=-1;
		for(i=7;line[i]!=' ';i++)
			temp[++j]=line[i];
		temp[++j]='\0';
		pushn(temp,lineno);
	}
}

//to find a macro name in the name table if it exists
int findname(char word[])
{
	("%s",frontnam->name);
	int i=1;
	struct nametab *temp=(struct nametab *)malloc(sizeof(struct nametab));
	temp=frontnam;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,word)==0)
		{
			return i;
		}
		temp=temp->link1;
		i++;
	}
	return 0;
}

//setting defalut value for the arguments in the call
void setdefault(char word[25])
{
	struct argument *tempa=(struct argument *)malloc(sizeof(struct argument));
	tempa=frontarg;
	while(tempa->link1!=NULL)
	{
		tempa=tempa->link1;
	}
	strcpy(tempa->value2,word);
}

//to create argument table for a macro with all the arguments that might be passed
void argtab()
{
	int i=1,j,startword=0;
	int s,e;
	char word[25];
	struct argument *tempa=(struct argument *)malloc(sizeof(struct argument));
	struct definition *tempd=(struct definition *)malloc(sizeof(struct definition));
	struct nametab *tempn=(struct nametab *)malloc(sizeof(struct nametab));
	tempn=frontnam;
	tempd=frontdef;
	while(i!=nameno)
	{
		tempn=tempn->link1;
		i++;
	}
	s=tempn->start;
	
	i=1;
	while(i!=s)
	{
		tempd=tempd->link1;
		i++;
	}
	char line[100];
	strcpy(line,tempd->string);
	i=0;
	while(line[i]!=' ')
	{
		if(line[i]=='\0')
			return;
		i++;
	}
	i++;
	while(line[i]!=' ')
	{
		if(line[i]=='\0')
			return;
		i++;
	}
	i++;
	j=-1;
	//loop to get all the arguments
	while(line[i]!='\0')
	{
		if(line[i-1]==',' || line[i-1]==' ')
			startword=1;
		if(line[i]==',' && startword==1)
		{
			startword=0;
			word[++j]='\0';
			pusha(word);
			j=-1;
		}
		else if(line[i]=='=' && startword==1)
		{
			word[++j]='\0';
			pusha(word);
			j=-1;
			startword=0;
		}
		else if(line[i]==',' && startword==0)
		{
			word[++j]='\0';
			setdefault(word);
			j=-1;
		}
		else
			word[++j]=line[i];
		i++;
	}
	//to get the final word that is stored
	word[j]='\0';
	if(startword==1)
		pusha(word);
	else
		setdefault(word);
}

//compare 2 strings
int search(char s1[],char s2[])
{
	int i=0;
	while(s1[i]!='\0' && s2[i]!='\0')
	{
		if(s1[i]==s2[i])
		{	
			i++;
		}
		else
			return 1;
	}
	return 0;
}

//assign corresponding value to the arguments in the table
void check(char line[])
{
	struct argument *tempa=(struct argument *)malloc(sizeof(struct argument));
	int i,j=-1,wordstart=0;
	char word[25];
	for(i=0;line[i]!='\0';i++)
	{
		if(line[i]=='&')
		{
			j=-1;
			wordstart=1;
			word[++j]=line[i];
		}
		else if(line[i]=='=')
		{
			wordstart=0;
			word[++j]='\0';
			j=-1;
			tempa=frontarg;
			while(search(tempa->value1,word)!=0)
			{
				tempa=tempa->link1;
			}
			i++;
			while(line[i]!=',' && line[i]!='\0')
			{
				word[++j]=line[i];
				i++;
			}
			word[++j]='\0';
			strcpy(tempa->value2,word);
			tempa=frontarg;
			j=-1;
		}
		else if(wordstart==1)
		{
			word[++j]=line[i];
		}
	}
}

//take up all the passed parameters and assign value using check() function
void process(char line[])
{
	int i=0,j=-1;
	char word[25];

	struct argument *tempa=(struct argument *)malloc(sizeof(struct argument));
	tempa=frontarg;
	while(line[i]!='\0')
	{
		if(line[i]=='&')
		{
			check(line);
			return;
		}
		i++;
	}
	
	i=0;
	while(line[i]!=' ')
	{
		if(line[i]=='\0')
			return;
		i++;
	}
	i++;
	j=-1;
	while(line[i]!='\0')
	{
		if(line[i]==',')
		{
			if(j>-1)
			{
				word[++j]='\0';
				strcpy(tempa->value2 , word);
			}
			j=-1;
			tempa = tempa->link1;
		}
		else
			word[++j]=line[i];
		i++;
	}
	if(j>-1 && (word[0]=='&'|| isalnum(word[0])!=0))	//to check that the word is not empty or the new line
		strcpy(tempa->value2 , word);
}

//expand function recursively called according to the macro call
void expand(char line[])
{
	int i=0,j=-1,s,e,wordstart=0,l,k;
	char word[25],str[100];
	struct definition *tempd=(struct definition *)malloc(sizeof(struct definition));
	struct nametab *tempn=(struct nametab *)malloc(sizeof(struct nametab));
	struct argument *tempa=(struct argument *)malloc(sizeof(struct argument));
	frontarg=NULL;
	reararg=NULL;
	tempn=frontnam;
	tempd=frontdef;
	tempa=frontarg;

	argtab();
	process(line);
	push();
	tempa=frontarg;

	i=1;
	while(i!=nameno)
	{
		tempn=tempn->link1;
		i++;
	}
	s=tempn->start;
	e=tempn->end;
	//reach the starting point of the macro definition
	i=1;
	while(i<s)
	{
		tempd=tempd->link1;
		i++;
	}
	i++;
	tempd=tempd->link1;
	int m=0;
	//loop till the end of the defintion
	while(i<e)
	{
		strcpy(str,tempd->string);
		k=0;
		j=-1;
		l=-1;
		//loop to substitute all the arguments with the parameters passed
		while(str[k]!='\0')
		{
			if(str[k]=='&')
			{
				word[++j]=str[k];
				wordstart=1;
			}
			
			else if(str[k]=='-' && str[k+1]=='>')
			{
				wordstart=0;
				word[++j]='\0';
				tempa=frontarg;
				while(search(tempa->value1,word)!=0 && tempa!=NULL)
					tempa=tempa->link1;
				m=0;
				if(tempa!=NULL)
				{
					while(tempa->value2[m]!='\0' && tempa!=NULL)
		 			{
						tempd->string[++l]=tempa->value2[m];
						m++;
					}
				}
				else
				{
					j=0;
					while(word[j]!='\0')
					{
						tempd->string[++l]=word[j];
						j++;
					}
				}
				k++;
				j=-1;
			}

			else if(wordstart==1)
				word[++j]=str[k];

			else if(wordstart==0)
				tempd->string[++l]=str[k];
			k++;
		}
		word[j]='\0';
		
		if(wordstart==1 && j!=-1)
		{
			j=-1;
			wordstart=0;
			tempa=frontarg;
			while(search(tempa->value1,word)!=0)
			{
				tempa=tempa->link1;
				if(tempa==NULL)
					break;
			}
			m=0;
			if(tempa!=NULL)
			{
				while(tempa->value2[m]!='\0' && tempa!=NULL)
				{
					tempd->string[++l]=tempa->value2[m];
					m++;
				}
			}
			
			else
			{
				j=0;
				while(word[j]!='\0')
				{
					tempd->string[++l]=word[j];
					j++;
				}
			}
		}
		tempd->string[++l]='\n';
		tempd->string[++l]='\0';
		strcpy(str,tempd->string);

		k=-1;
		//processing the line in the definition for nested call or definition
		for(j=0; str[j]!=' ' && str[j]!='\0' ;j++)
			word[++k]=str[j];
		word[++k]='\0';
		if(search(word,"%macro")==0)
		{
			tempd=tempd;
		}

		else if(word[0]==37 && word[2]=='e')
			tempd=tempd;
		
		else
		{
			nameno=findname(word);
			if(nameno!=0)
				expand(str);
			else
				printf("%s",str);
		}
		
		tempd=tempd->link1;
		i++;
	}
	//pop the argument table so as to restore argument table for recursive call
	pop();
}

void main()
{
	int i,j,k;
	char line[100],firstword[25];
	FILE *f;
	f=fopen("input.txt","r");

	//loop to process line by line to get macro definiton or call and print line if neither exists
	while(fgets(line,sizeof(line),f)!=NULL)
	{
		j=-1;
		for(i=0;line[i]!=' ' && line[i]!='\0';i++)
		{
			firstword[++j]=line[i];
		}
		firstword[++j]='\0';
		if(strcmp(firstword,"%macro")==0)
		{
			while(1)
			{
				define(line);
				if(level!=0)
					fgets(line,sizeof(line),f);
				else if(level==0)
					break;
			}
		}
		
		else
		{
			nameno=findname(firstword);
			//printf("\n%d",nameno);
			if(nameno!=0)
				expand(line);
			else
				printf("%s",line);
		}
	}
	/*
	struct definition *temp=(struct definition *)malloc(sizeof(struct definition));
	temp=frontdef;
	while(temp!=NULL)
	{
		printf("%s",temp->string);
		temp=temp->link1;
	}
	struct nametab *tempn=(struct nametab *)malloc(sizeof(struct nametab));
	tempn=frontnam;
	while(tempn!=NULL)
	{
		printf("\n%s %d %d",tempn->name,tempn->start,tempn->end);
		tempn=tempn->link1;
	}
	printf("\n");
	struct argument *tempa=(struct argument *)malloc(sizeof(struct argument));
	tempa=frontarg;
	while(tempa!=NULL)
	{
		printf("\n%s %s",tempa->value1,tempa->value2);
		tempa=tempa->link1;
	}
	*/
}