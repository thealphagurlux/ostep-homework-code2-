#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int rc = fork();

    if (rc == 0) // child
    {
        printf(" running child process \n");
        char * const argv[] = {"ls", NULL};
        char * const envp[] = {NULL};

        //execl("/bin/ls", "ls", NULL);
        //execlp("ls", "ls", NULL);
        //execle("/bin/ls", "ls", NULL, envp); 
        execv("/bin/ls", argv);
        //execvp("ls", argv);
        
    }
    else if (rc > 0) // parent
    {
        wait(NULL);
    }
    else
    {
        fprintf(stderr, "Error occurred during fork()");
    }
}
/**************
Josh Wakin

execl and execv are nearly identical (have very little difference). They can execute commands given absolute path.
execlp and execvp are nearly identical. They can execute commands included within the PATH enviornment given the command name.

**************/
