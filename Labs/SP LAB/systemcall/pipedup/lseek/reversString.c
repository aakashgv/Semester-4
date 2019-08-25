#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(int argc, char *argv[]){
	int fd1,fd2;
	char buf;
	int i=0,filesize=0;
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR);
	while(read(fd1,&buf,1)>0)
	    filesize++;
	    printf("%d\n",filesize);
	while(++i<=filesize){
	    lseek(fd1,-i,SEEK_END);
	    read(fd1,&buf,1);
	    write(fd2,&buf,1);
	}
	close(fd1);
	close(fd2);
}
