#include <pthread.h>
#include <stdio.h>

void *c(void *val);

int main () {

	pthread_t t1;
	pthread_t t2;
	long val1 = 5;
	long val2 = 50;

	pthread_create(&t1, NULL, c, (void *) &val1);
	pthread_create(&t2, NULL, c, (void *) &val2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}

void *c( void *val) {

	long *v = (long *) (val);
	printf ("C %ld\n", *v);

	return NULL;
}
