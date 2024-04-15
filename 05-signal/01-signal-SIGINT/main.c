#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void sig_handler1(int num)
{
	printf("\nIm signal handler1: %d\n", num);
	//while (1);
	// exit(EXIT_SUCCESS);
}

void sig_handler2(int num)
{
	printf("Im signal handler2: %d\n", num);
}

void sig_handler3(int num)
{
    printf("Im signal handler3: %d\n", num);
	exit(EXIT_SUCCESS);
}

int main(void)
{
  	if (signal(SIGINT, sig_handler1) == SIG_ERR) {
		fprintf(stderr, "Cannot handle SIGINT\n");
		exit(EXIT_FAILURE);
	}

	signal(SIGKILL, sig_handler2);
	signal(SIGTERM, sig_handler3);

	printf("process ID: %d\n", getpid());
	while (1)
	{
		// do nothing.
	 	printf("hello\n");
		sleep(2);
	}


    return 0;
}



