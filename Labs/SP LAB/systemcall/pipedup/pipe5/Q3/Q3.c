#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){

int pipe1[2],pipe2[2],id1,id2;
pipe(pipe1);
id1=fork();

if(id1==0){
pipe(pipe2);
id2=fork();
    if(id2==0){
    close(1);
    dup(pipe2[1]);
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    printf("\n ls:- \t");
    execlp("ls","ls",NULL);
                }
    else{
    close(0);
    dup(pipe2[0]);
    close(1);
    dup(pipe1[1]);
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    printf("\n sort:- \t");
    execlp("sort","sort",NULL);
         }
}
else{
close(0);
dup(pipe1[0]);
close(pipe1[0]);
close(pipe1[1]);
printf("\n wc:- ");
execlp("wc","wc",NULL);
    }
    
return 0;

}
