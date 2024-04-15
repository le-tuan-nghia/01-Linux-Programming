#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    pid_t child_pid;
    int a = 0;

    printf("Gia tri khoi tao cua a: %d\n", a);

    child_pid = fork();
    if (0 == child_pid) {
        printf("\nI'm the child process, a: %d\n", ++a);
        printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
    } else {
        printf("\nI'm the parent process, a: %d\n", ++a);
        printf("My PID is: %d\n", getpid());
        while(1);
    }

    return 0;
}





