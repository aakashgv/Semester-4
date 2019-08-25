#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


void main(int argc,char *argv[]){
char buffer;
int fsz;
int fd1,fd2;
int n,i;
fsz=0; i=0;
fd1=open(argv[1],O_RDONLY);
fd2=open(argv[2],O_CREAT|O_WRONLY,S_IWUSR|S_IRUSR);

while(read(fd1,&buffer,1)>0)
fsz++;
printf("\n number of letters counted = %d",fsz);                              

while(++i<=fsz){
  lseek(fd1,-i,SEEK_END);
  read(fd1,&buffer,1);
  write(fd2,&buffer,1);
               } 
close(fd1);
close(fd2);
}
