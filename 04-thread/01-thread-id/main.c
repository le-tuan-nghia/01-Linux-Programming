#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_t thread_id1, thread_id2;

typedef struct {
    char name[30];
    char msg[30];
} thr_data_t;

static void *thr_handle(void *args) 
{
    pthread_t tid = pthread_self();
    thr_data_t *data = (thr_data_t *)args;

    if (pthread_equal(thread_id1, tid))
        printf("Hello thread_id1\n");
    else if (pthread_equal(thread_id2, tid))
        printf("Hello %s, welcome to join %s\n", data->name, data->msg);
}

int main(int argc, char *argv[])
{
    int ret;
    thr_data_t data = {0};

    strncpy(data.name, "loclx", sizeof(data.name));
    strncpy(data.msg, "thread programming\n", sizeof(data.msg));

    if (ret = pthread_create(&thread_id1, NULL, &thr_handle, NULL)) {
        printf("pthread_create() ret = %d\n", ret);
        return -1;
    }

    sleep(2);

    if (ret = pthread_create(&thread_id2, NULL, &thr_handle, &data)) {
        printf("pthread_create() ret = %d\n", ret);
        return -1;
    }

    sleep(5);

    return 0;
}





