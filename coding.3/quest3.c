#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int signum) {
    printf("goodbye\n");
    exit(0);
}

int main (int argc, char const *argv[]) {
    int parent_pid = getpid();
    int rc = fork();
    if (rc == 0) 
    {
        printf("hello\n");
        kill(parent_pid, SIGCONT);
        exit(0);
    }
    else if (rc > 0) 
    {
        
        signal(SIGCONT, sig_handler);
        pause();
    }
    else
    {
        printf("error\n");
        return 1;
    }
}


/***********************
Josh Wakin

No you are unable to make the child process run first without using the wait function, so
hello will always print first.
***********************/
