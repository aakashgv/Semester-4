#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main(){

int fd[2];
int childpid;
char readbuf[80];
char string[30];
int i,l,b,area;
char len[10],bred[10];

printf("\n enter the length and the breadth of rectangle- ");
gets(string);

pipe(fd);
childpid=fork();

if(childpid==0){
close(fd[0]);

write(fd[1],string,strlen(string)+1);

               }
else{
close(fd[1]);
read(fd[0],readbuf,sizeof(readbuf));

int n=strlen(readbuf);
int j;
                 
for(i=0;i<n;i++){
    if(readbuf[i]== ' '){
       j=i;
        break;
                         }
            
                }
                
for(i=0;i<j;i++){
len[i]=readbuf[i];
                }                
len[i]='\0';

int temp=0;
for(i=j+1;i<n;i++){
   bred[temp++]=readbuf[i];
                  }

}                
bred[i]='\0';

l=atoi(len);
b=atoi(bred);                
                
printf("\n l=%d  b=%d",l,b);
area=l*b;
printf("\n the area of rectangle- %d",area);                
                
                  }

