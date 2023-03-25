#include <stdio.h>
#include <pthread.h>
 
// size of array
#define MAX 16
 
// maximum number of threads
#define MAX_THREAD 4
 
 
int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int sum[4] = { 0 };
int part = 0;
 
void* sum_array(void* arg)
{
    // Each thread computes sum of 1/4th of array
    int thread_part = part++;
 
    for (int i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++)
        sum[thread_part] += a[i];
}
 
// Driver Code
int main()
{
 
    int total_sum = 0;

    pthread_t threads[MAX_THREAD];
 
    // Creating 4 threads
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);
 
    // joining 4 threads i.e. waiting for all 4 threads to complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);
 
    // adding sum of all 4 parts
    for (int i = 0; i < MAX_THREAD; i++)
        total_sum += sum[i];

    printf ("sum is %d\n", total_sum);
 
    return 0;
}
