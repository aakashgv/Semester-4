#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>



int disp() {
    printf("Process ID:%d  Parent Process ID: %d\n",getpid(), getppid() );
    return 1;
}

int func(int n) 
{
    if (n == 1)
    { 
        return 0;
    }
    int pid = fork(); 
    if (pid == -1) {
        exit(0);
    }
    if (pid==0) { 
        disp();
        n--;
        func(n);
        exit(0);
    }
    else {
       wait(NULL);
    } 
    return 0;   
}


int main()
{
    int n;
    printf("Enter the value for n:  ");
    scanf("%d",&n);
    func(n); 
    return 0;
}
