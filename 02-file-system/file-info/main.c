#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "strUtils.h"
#include "timeUtils.h"

void main()
{
    char fileName[] = "test.txt";
    writeLine("Tạo file");
    FILE* fileTest = fopen(fileName, "w");

    char str[] = "Xin chao cac ban!\n";
    writeLine("Ghi lời chào");
    fwrite(str, 1, sizeof(str), fileTest);

    writeLine("Ghi thời gian");
    fprintf(fileTest, "Thoi gian hien tai: %s\n", timeNowInStr());

    writeLine("Đóng file");
    fclose(fileTest);

    writeLine("Đọc thông tin file");
    struct stat sb;     // Chú ý khai báo 2 include: stat.h và types.h
    if (-1 == lstat(fileName, &sb))
    {
        writeLine("Lỗi đọc thông tin file!");
        return;
    }

    printf("File type: 0x%X\n", sb.st_mode);
    printf("File type: ");
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:   printf("block device\n");       break;
        case S_IFCHR:   printf("character device\n");   break;
        case S_IFDIR:   printf("directory\n");          break;
        case S_IFIFO:   printf("FIFO/pipe\n");          break;
        case S_IFLNK:   printf("symlink\n");            break;
        case S_IFREG:   printf("regular file\n");       break;
        case S_IFSOCK:  printf("socket\n");             break;
        default:        printf("unknown?\n");
    }

    printf("File size: %d\n", sb.st_size);
    printf("Last status change:     %s", ctime(&sb.st_ctim.tv_sec));
    printf("Last file access:       %s", ctime(&sb.st_atim.tv_sec));
    printf("Last file modification: %s", ctime(&sb.st_mtim.tv_sec));
}
