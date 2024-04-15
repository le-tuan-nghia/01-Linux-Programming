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
        // while(1);

        sleep(5);
        exit(0);
    } else {
        printf("\nI'm the parent process, pid: %d\n", getpid());
        rv = wait(&status);
        if (rv == -1) {
            printf("\nwait() unsuccessful\n");
        }

        /*  Parent wait done! rv = 60463, status = 9 
            rv: là pid của child process
            status: là kiểu kill process */
        printf("Parent wait done! rv = %d, status = %d\n", rv, status);

        if (WIFEXITED(status)) {
            printf("Normally termination, status = %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Abnormally termination, kill by signal, value = %d\n", WTERMSIG(status));
        }

    }

    return 0;
}





