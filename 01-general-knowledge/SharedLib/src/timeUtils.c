#include<sys/time.h>
#include "timeUtils.h"

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
