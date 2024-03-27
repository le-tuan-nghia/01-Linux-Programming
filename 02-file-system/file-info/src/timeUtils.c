#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "timeUtils.h"

char* timeNowInStr(void)
{
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    // Nếu không dùng biến static, giá trị trả về str sẽ thành null cho bộ nhớ chuỗi bị giải phóng
    static char str[100];
    sprintf(str, "%02d/%02d/%04d %02d:%02d:%02d", tm_struct->tm_mday, tm_struct->tm_mon, tm_struct->tm_year + 1900, 
        tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);

    return str;
}

long long timeInMs(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);

    long long sec2ms = (long long) tv.tv_sec * 1000;
    long long us2ms = (long long) tv.tv_usec / 1000;

    return (sec2ms + us2ms);
}

void delayMs(int ms)
{
    long long startTime = timeInMs();
    long long endTime = startTime + ms;

    while (1)
    {
        long long current = timeInMs();
        if (current >= endTime) break;
    }
}
