#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0)
    {
        int wc = wait(NULL);
        printf("I am child process\n");
        printf("Return code from wait() is %d\n", wc);
    }
    else if (rc > 0) 
    {
        printf("I am parent process\n");
    }
    else
    {
        fprintf(stderr, "Error Occurred during fork()");
    }
}


/*****************
Josh Wakin

wait on success, returns the process ID of the terminated child; on error, -1 is returned.

If we use wait in child process then wait returns -1. Because, there is no child of child. So, there is no wait for any process to exit.
*****************/
