#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    int numb_write;
    char buf1[12] = "programming";

    fd = open("hello.txt", O_RDWR | O_CREAT, 0667);
    if (-1 == fd)
    {
        printf("open hello.txt error");
        return;
    }

    while(1)
    {
        numb_write = write(fd, buf1, strlen(buf1));
        sleep(2);
        // printf("Write %d bytes to hello.txt\n", numb_write);
    }

    close(fd);
    return 0;
}





