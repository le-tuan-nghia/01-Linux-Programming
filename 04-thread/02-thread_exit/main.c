#include "/home/pnc/Training/01-Linux-Programming/utils/inc/utils.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_t thread_id3;
static void *thr_handle3(void *args) 
{
    pthread_detach(pthread_self());
}

int main(int argc, char *argv[])
{
    int ret;
    int count = 0;

    while(1) {
        if (ret = pthread_create(&thread_id3, NULL, &thr_handle3, NULL)) {
            writeLine("pthread_create() ret = %d", ret);

            // Thread create error: 32754
            writeLine("Thread create error: %d", count);
            break;
        }

        // pthread_join(thread_id3, NULL);

        count++;
        if (count % 1000 == 0)
            writeLine("Thread create: %d", count);
    }

    return 0;
}





