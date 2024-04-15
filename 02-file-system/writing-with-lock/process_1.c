#include <stdio.h>
#include <fcntl.h>
#include <sys/file.h>

int main(void)
{
    int fd, op;
    int numb_write;
    char buf1[12] = "hello";
    char buf2[12] = "linux";

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
        numb_write = write(fd, buf2, strlen(buf2));
        op = flock(fd, LOCK_UN);
        sleep(2);
    }

    close(fd);
    return 0;
}





