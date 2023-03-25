#include <pthread.h>
#include <stdio.h>

void *c(void *val);

int main () {

	pthread_t t1;
	pthread_t t2;
	long val1 = 5;
	long val2 = 50;

#if 1
	c ((void *) &val1);
	c ((void *) &val2);
#endif

#if 0
	pthread_create(&t1, NULL, c, (void *) &val1);
	pthread_create(&t2, NULL, c, (void *) &val2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
#endif

	return 0;
}

void *c( void *val) {

	long sum = 0;
	long *v = (long *) (val);
	
	for (int i = 0; i < 1000000000; i++) 
		sum += *v;

	return NULL;
}
