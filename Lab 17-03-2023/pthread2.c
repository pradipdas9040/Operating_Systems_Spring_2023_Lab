#include <pthread.h>
#include <stdio.h>

void *c(void *val);

int main () {

	pthread_t t1;
	long val = 5;

	pthread_create(&t1, NULL, c, (void *) &val);
	pthread_join(t1, NULL);

	return 0;
}

void *c( void *val) {

	long *v = (long *) (val);
	printf ("C %ld\n", *v);

	return NULL;
}
