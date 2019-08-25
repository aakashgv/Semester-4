#include<stdio.h>

main()
{
    int id;

    
    id=fork();

    if(id==0)
    {
        printf("Child has started: %d\n ",getpid());
        printf("Parent of this child: %d\n",getppid());
        printf("First Item of Child\n");
        printf("Going to Sleep\n");
        sleep(5);
        printf("Second Item of Child\n");
    }
    else
    {
        printf("Parent ID: %d\n",getpid());
        printf("Parent of Parent: %d\n",getppid());
    }

    printf("Fork completed");
}
