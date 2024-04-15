#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Run command ls -lah after 2 seconds\n\n");

    sleep(2);

    // Danh sách các đối số của hàm execl phải kết thúc bằng con trỏ null
    execl("/bin/ls", "ls", "-l", "-a", "-h", NULL);

    return 0;
}





