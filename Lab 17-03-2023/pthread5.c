#include "bankUtils.h"
#include <pthread.h>
#include <stdio.h>

void *deposit( void *amount);

int main() {

	int before = read_balance();
	printf ("Before %d\n", before);

	pthread_t t1;
	pthread_t t2;

	int deposit1 = 200;
	int deposit2 = 300;

	pthread_create(&t1, NULL, deposit, (void *) &deposit1);
	pthread_create(&t2, NULL, deposit, (void *) &deposit2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);


	int after = read_balance();
	printf ("After %d\n", after);

	return 0;
}

void* deposit (void *amount) {

	int acb = read_balance();

	acb += *((int *) amount);

	write_balance (acb);

	return NULL;
}
