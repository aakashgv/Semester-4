
#include  <stdio.h>
#include  <string.h>
#include  <math.h>
#include  <ctype.h>
#include  <sys/types.h>
#include <unistd.h>

#define   MAX_COUNT  300
#define SIZE 50

char expr[20];
char s[SIZE];
char stack[20];
int top = -1;
int i;
int ctr;
int topOper=-1;

int operate(int a,int b,char oper){
    int res=0;
switch(oper){
    case '+':res=a+b;break;
    case '-':res=a-b;break;
    case '*':res=a*b;break;
    case '/':res=a/b;break;
}
return res;
}


char *rev(char *str){
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}



int pr(char elem){                 
    switch(elem){
    case '#': return 0;
    case ')': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}


void push(char x){
    stack[++top] = x;
}

void push1(char elem){                       
    s[++top]=elem;
}

char pop1(){                      
    return(s[top--]);
}
 
char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
 
int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

void  CP();   
void  PP();               


void  main(void){
	char expression[20];
	printf("Expression: ");
    scanf("%[^\n]%*c",expression);

     pid_t  PrID;
     PrID = fork();
     if (PrID == 0) 
          CP(expression);
     else 
          PP(expression);
}


void  CP(char expression[100]){

	pid_t PrIdent;
	PrIdent= fork();

	if(PrIdent==0){
	
	    printf("Child->Child\n");
	        int i=0,k=0;
	        char infx[50],prfx[50],ch,elem;

			push1('#');
    rev(expression);
    while( (ch=expression[i++]) != '\0'){
        if( ch == ')') push1(ch);
        else
            if(isalnum(ch)) prfx[k++]=ch;
            else
                if( ch == '('){
                    while( s[top] != ')')
                        prfx[k++]=pop1();
                    elem=pop1(); 
                }
                else{       
                    while( pr(s[top]) > pr(ch) )
                        prfx[k++]=pop1();
                    push1(ch);
                }
    }
    while( s[top] != '#')     
        prfx[k++]=pop1();
    prfx[k]='\0';          
    rev(prfx);
    rev(expression);
	printf("Prefix: %s \n", prfx);    
	
	}
	
	
	else{
    printf("Child->Parent \n");
    printf("Infix: %s \n", expression);
   }
}


void  PP(char expression[100]){
    printf("Parent\n");
 char *e, x;
 e = expression;
 printf("Postfix: ");
 
 while(*e != '\0'){
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')'){
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else{
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
   while(top != -1){
        printf("%c",pop());
    }    
    printf("\n");
}

