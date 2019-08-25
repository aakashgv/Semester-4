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
int i,sq,j;
char num[10];

printf("\n enter the number to be squared- ");
gets(string);

pipe(fd);
childpid=fork();

if(childpid==0){
close(fd[0]);

write(fd[1],string,strlen(string)+1);
exit(0);
               }
else{
close(fd[1]);
read(fd[0],readbuf,sizeof(readbuf));

int n=strlen(readbuf);

                 
for(i=0;i<n;i++){
num[i]=readbuf[i];
                }                
num[i]='\0';


}                


j=atoi(num);
printf("\n the number is j=%d ",j);
sq=j*j;
printf("\n the square of number is- %d",sq);                
                
                  }

