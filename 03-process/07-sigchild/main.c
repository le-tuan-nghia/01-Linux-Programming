#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_hanlder(int signum)
{
    printf("I'm in func()\n");
    wait(NULL);
}

int main(int argc, char *argv[])
{
    pid_t child_pid;

    child_pid = fork();
    if (0 == child_pid) {
        printf("\nI'm the child process, pid: %d\n", getpid());
    } else {
        printf("\nI'm the parent process, pid: %d\n", getpid());
        signal(SIGCHLD, signal_hanlder);

        printf("Parent do something\n");
        while(1);
    }

    return 0;
}





