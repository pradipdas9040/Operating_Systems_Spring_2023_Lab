#include "bankUtils.h"
#include <pthread.h>
#include <stdio.h>

void *deposit( void *amount);
pthread_mutex_t lockBalance;


int main() {

	int before = read_balance();
	printf ("Before %d\n", before);

	pthread_t t1;
	pthread_t t2;

	int deposit1 = 200;
	int deposit2 = 300;

	// Create Lock
	pthread_mutex_init (&lockBalance, NULL);

	pthread_create(&t1, NULL, deposit, (void *) &deposit1);
	pthread_create(&t2, NULL, deposit, (void *) &deposit2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	// Destroy Lock
	pthread_mutex_destroy (&lockBalance);

	int after = read_balance();
	printf ("After %d\n", after);

	return 0;
}

void* deposit (void *amount) {

	// Lock
	pthread_mutex_lock (&lockBalance);

	int acb = read_balance();

	acb += *((int *) amount);

	write_balance (acb);

	// UnLock
	pthread_mutex_unlock (&lockBalance);

	return NULL;
}
