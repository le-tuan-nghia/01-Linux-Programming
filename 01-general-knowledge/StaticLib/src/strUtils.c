#include <time.h>
#include<sys/time.h>
#include "strUtils.h"

void writeLine(char *str)
{
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    
    struct timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    printf("%02d:%02d:%02d.%03d> ", tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec, milli);
    printf(str);
    printf("\n");
}