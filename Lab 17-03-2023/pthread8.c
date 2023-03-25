#include <stdio.h>
#include <pthread.h>
 
// size of array
#define MAX 16
 
// maximum number of threads
#define MAX_THREAD 4
 
 
int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int sum = 0;
int prod = 1;
 
void* prod_array(void* arg)
{
    for (int i = 0; i < 16; i++)
        prod *= a[i];
}

void* sum_array(void* arg)
{
    for (int i = 0; i < 16; i++)
        sum += a[i];
}
 
// Driver Code
int main()
{

#if 1
    pthread_t t1, t2;
 
    // Creating 2 threads
    pthread_create(&t1, NULL, sum_array, (void*)NULL);
    pthread_create(&t2, NULL, prod_array, (void*)NULL);
 
    // joining 2 threads i.e. waiting for all 2 threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
#endif

 	//sum_array((void *) NULL);	
 	//prod_array((void *) NULL);	
    printf ("sum is %d\n", sum);
    printf ("prod is %d\n", prod);
 
    return 0;
}
