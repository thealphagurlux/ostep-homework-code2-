#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child process
    {
        close(STDOUT_FILENO);
        printf("Hello World. Can you see this?\n");
    }
    else if (rc > 0)
    {
        wait(NULL);
        printf("I am parent process\n");
    }
    else 
    {
        printf("Error occurred during fork()\n");
    }
}


/***********************
Josh Wakin

Closing stdout file descriptor we won't be able to write something on the screen using printf. However no error would happen.
***********************/
