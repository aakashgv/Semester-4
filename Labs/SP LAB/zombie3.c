#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
 
int main ()
{
  pid_t child_pid;
  int child_status;
 
  child_pid = fork ();
  if (child_pid > 0) {
    printf("Parent Process ID: %d\n", getpid());    
    sleep(3); 
    exit(0);
  }
  else if (child_pid == 0) {
    printf("Child Process ID: %d\n", getpid());
    exit(0);    
  }
  else {
    printf("Error Value: %d", child_pid);
    exit (-2);
  }
  return 0;
}
