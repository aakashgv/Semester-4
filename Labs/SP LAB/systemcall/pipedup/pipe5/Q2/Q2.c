#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
int fd1,fd2,fd3,s1=0,s2=0,i=0,j=0;
char buf;

fd1=open("f1.txt",O_RDONLY);
fd2=open("f2.txt",O_RDONLY);
fd3=open("f3.txt",O_CREAT|O_WRONLY|O_TRUNC,777);

while(read(fd1,&buf,1)>0){
s1++;
                       }
                       
while(read(fd2,&buf,1)>0){
s2++;
                       }
                       
lseek(fd1,0,SEEK_SET);                       
lseek(fd2,0,SEEK_SET);
lseek(fd3,0,SEEK_SET);

while((++i<=s1)&&(++j<=s2)){
if(i<=s1){
read(fd1,&buf,1);
write(fd3,&buf,1);
         }

if(j<=s2){
read(fd2,&buf,1);
write(fd3,&buf,1);
         }
else{
printf("\n no more data in file 3\n");
   }

close(fd1);
close(fd2);
close(fd3);
}





return 0;
           }

