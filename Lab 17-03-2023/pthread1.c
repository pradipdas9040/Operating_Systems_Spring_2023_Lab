#include <pthread.h>
#include <stdio.h>

void *c();

int main () {

	pthread_t t1;
	pthread_create(&t1, NULL, c, NULL);
	//pthread_join(t1, NULL);

	return 0;
}

void *c() {
	printf ("C\n");
	return NULL;
}
