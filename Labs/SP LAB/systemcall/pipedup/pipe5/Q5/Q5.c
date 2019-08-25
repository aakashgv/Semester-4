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
int i,j;
char filename[10];

printf("\n enter the name of file to open- ");
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
filename[i]=readbuf[i];
                }                
filename[i]='\0';

int k=open(filename,O_RDONLY);
char opbuf[100];
printf("\n the contents of file %s is-\n",filename);
while(read(k,filename,sizeof(filename))>0)
printf("%s",filename);
}                


                
                  }

