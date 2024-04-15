#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t child_pid;
    int status, rv;

    child_pid = fork();
    if (0 == child_pid) {
        printf("\nI'm the child process, pid: %d\n", getpid());
        printf("\nChild process termination\n");
    } else {
        while(1);
    }

    return 0;
}





