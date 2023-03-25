#include <pthread.h>
#include <stdio.h>
#include <stdint.h>

void *myThread(void *args)
{
    return (void *)(intptr_t)42;
}

int main(void)
{
    pthread_t tid;
    void *status;
    int ret;

    pthread_create(&tid, NULL, myThread, NULL);
    ret = pthread_join(tid, &status);

    if (ret) {
        fprintf(stderr, "pthread_join() failed\n");
        return -1;
    }

    /* pthread_join() copies the exit status (namely 42) of the target thread
     * into the location pointed to by retval (namely &status), &status points
     * to void *, so we need to cast void * to int.
     */
    printf("%ld\n", (intptr_t)status);

    return 0;
}
