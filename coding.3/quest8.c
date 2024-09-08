int
main(int argc, char *argv[])
{
    // Setup our pipe
    char buff[BUFSZE];
    int p[2];

    if (pipe(p) < 0)
      exit(1);

    int rc1 = fork();
    if (rc1 < 0) {
        // fork failed; exit
        fprintf(stderr, "fork #1 failed\n");
        exit(1);
    } else if (rc1 == 0) {
	     
       printf(" Child #1 ");
       close(p[0]);  
       dup2(p[1], 1); 
       printf("_This is getting sent to the pipe_");
    } else {
        int rc2 = fork();
        if (rc2 < 0) {
          fprintf(stderr, "fork #2 failed\n");
          exit(1);
        } else if (rc2 == 0) {
          printf(" Child #2 ");
          close(p[1]);     
          dup2(p[0], 0);    

          char buff[512];   
          read(STDIN_FILENO, buff, 512); 
          printf("%s", buff);     

        } else {

          int wc = waitpid(rc2, NULL, 0);
          printf("goodbye");
        }
    }
    return 0;
}
/***************************
Josh Wakin

We create a pipe with the pipe() system call, exiting if unsuccessful. We create the first child, which we call A, with a fork() call, then, in the section of code running for the parent, we make a second fork() call to make the second child, which we call B. Child A uses dup2 to make stdout point to the write end of the pipe and passes a string to the write end of the pipe.

Child B uses dup2 to make stdin point to the read end of the pipe and reads from the read end of the pipe. This connects the stdout of A to the stdin of B.
***************************/
