#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();
    
    if (rc == 0) // child
    {
        printf("I am child process. My PID is %d\n", getpid());
        exit(0);
    }
    else if (rc > 0)
    {
        int status;
        waitpid(rc, &status, 0);
        printf("I am parent process. My PID  is %d\n", getpid());        
    }
    else
    {
        fprintf(stderr, "Error occurred during fork()");
    }
}
/***********************
Josh Wakin

waitpid is used when we want to wait or a specific child process rather than waiting for all child processes to exit.It also allows to select more behaviours.

***********************/
