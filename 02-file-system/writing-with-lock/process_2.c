#include <stdio.h>
#include <fcntl.h>
#include <sys/file.h>

int main(void)
{
    int fd, op;
    int numb_write;
    char buf1[12] = "_programming_";

    fd = open("hello.txt", O_RDWR | O_CREAT | O_APPEND, 0667);
    if (-1 == fd)
    {
        printf("open hello.txt error");
        return;
    }

    while(1)
    {
        op = flock(fd, LOCK_SH);
        numb_write = write(fd, buf1, strlen(buf1));
        op = flock(fd, LOCK_UN);
        sleep(2);
    }

    close(fd);
    return 0;
}





