#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <sys/types.h> 
#include <unistd.h> 
char stack[20];
int top =-1;

char s[10];
int top1=-1;
void pushed(char elem)
{                       
  s[++top1]=elem;
}
 
char poped()
{                     
    return(s[top1--]);
}


char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int precedence(char ch){

    if ( ch == '(') return 1;

    if ( ch == '+' || ch == '-') return 2;
    if ( ch == '*' || ch == '/' || ch == '%') return 3;


    if ( ch == '^') return 4;
    if ( ch == 'f') return 5;



}
int pr(char elem)
{                 
    switch(elem)
    {
    case '#': return 0;
    case ')': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    case '^':return 4;
    }
}
 
void push(char x)
{
    stack[++top] = x;
}


char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}



 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
}
 

int main(){

char exp[10],prfx[10],pofx[10],ch,elem;
int l,i,v,sum,k;
v=0;
printf("\n enter an expression- ");
scanf("%s",exp);

l=strlen(exp);


if (fork()== 0){
      
        if(fork()!=0){
//covert to postfix and print
   k=0;
   i=0;
   char *e,x;

  printf("\n the postfix expression is- \n");
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
            
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
             
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop());
                push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
  printf("\n");              
                          }
                   
  else{
//convert to prefix and print 
 k=0;
 i=0; 
      pushed('#');
    strrev(exp);
    while( (ch=exp[i++]) != '\0')
    {
        if( ch == ')') pushed(ch);
        else
            if(isalnum(ch)) prfx[k++]=ch;
            else
                if( ch == '(')
                {
                    while( s[top1] != ')')
                        prfx[k++]=poped();
                    elem=poped(); /* Remove ) */
                }
                else
                {       /* Operator */
                   while( pr(s[top1])>=pr(ch) )
                        prfx[k++]=poped();
                        pushed(ch);
                }
    }
    while( s[top1] != '#')     /* Pop from stack till empty */
        prfx[k++]=poped();
    prfx[k]='\0';          /* Make prfx as valid string */
    strrev(prfx);
    
    printf("\n Prefix Expn: %s",prfx);


                
       }
            }
else{
//eval infix:


if((exp[0]=='+')||(exp[0]=='-')||(exp[0]=='*')||(exp[0]=='/')||(exp[0]=='%')||(exp[0]=='^')||(exp[l-1]=='+')||(exp[l-1]=='-')||(exp[l-1]=='*')||(exp[l-1]=='/')||(exp[l-1]=='%')||(exp[l-1]=='^') ){
           printf("\n the given infix expression is wrong ");
            v++;
                                                   }
 for(i=0;i<l;i++){
   if( ((exp[i]=='+')&&(exp[i+1]=='+'))||((exp[i]=='-')&&(exp[i+1]=='-'))||((exp[i]=='*')&&(exp[i+1]=='*'))||((exp[i]=='/')&&(exp[i+1]=='/'))||((exp[i]=='%')&&(exp[i+1]=='%'))||((exp[i]=='^')&&(exp[i+1]=='^')) ){
		printf("\n the given infix expression is wrong ");
                                        v++;                           }
                                                  
  
                 }
if(v==0){
  printf("\n given string is a proper infix expression");
    } 


//end infix eval
   }
return 0;
          }
