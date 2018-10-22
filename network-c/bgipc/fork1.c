#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t pid;
    int rv;

    switch(pid = fork()){
        case -1:
            perror("fork"); /* Something went wrong */
            exit(1); /* Parent exits */
        case 0:
            printf(" CHILD: This is the child process!\n");
            printf(" CHILD: My PID is %d\n", getpid());
            printf(" CHILD: Enter my exits status (make it small): ");
            scanf(" %d", &rv);
            printf("I'm outta here!\n");
            exit(rv);
        default:
            printf(" PARENT: This is the parent process!\n");
            printf(" PARENT: My PID is %d\n", getpid());
            printf(" PARENT: I'm now waiting for my children to exits() ...\n");
            wait(&rv);
            printf(" PARENT: My child's exit status is : %d\n", WEXITSTATUS(rv));
            printf("PARENT: I'm outta here!!!\n");
    }
    return 0;
}
