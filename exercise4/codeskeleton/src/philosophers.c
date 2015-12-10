#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define     SLEEP_TIME       2     /* maximum amount of time */

sem_t gabel[ 5 ];/* semaphores for all forks */

int leftFork( int tid )
{
	tid--;
	while( tid < 0 )
		tid = ( 5 + tid );

	return tid % 5;
}

int rightFork( int tid )
{
	while( tid < 0 )
		tid = ( 5 + tid );

	return tid % 5;
}

void eating( int tid )
{
    sem_wait(&gabel[leftFork(tid)]);
		sem_wait(&gabel[rightFork(tid)]);

		printf("eating\n" );
		sleep(rand()%SLEEP_TIME);

		sem_post(&gabel[leftFork(tid)]);
		sem_post(&gabel[rightFork(tid)]);
}

void hungry( int tid )
{
	printf("Philosopher %d: I'm hungry!\n", tid );
}

void thinking( int tid )
{
	printf("Philosopher %d is thinking!\n", tid );
	sleep( rand() % SLEEP_TIME );
}

void* philosopher(void *arg)
{
	int i;
    int tid = *( ( int* ) arg );

	/*philosopher thread thinks, becomes hungry, ...*/

	for (i=0;i<10;i++) {
		thinking( tid );
		hungry( tid );
		eating( tid);
	}
	return 0;
}

int main()
{
	int i;
    int id[ 5 ]; /* id parameter */
    pthread_t thread[ 5 ]; /* threads for all philosophers */

    srand( time( NULL ) );

    /* initalize semaphores */
	for( i = 0; i < 5; i++ ) {
        if( sem_init( &gabel[ i ], 0, 1 ) != 0 ) {
            printf("ERROR: could not create initalize semaphore %d\n", i );
			exit( EXIT_FAILURE );
        }
    }

	/* create philosopher threads */
	for (i=0; i<5; i++) {
		id[ i ] = i;
        /* creation of philosopher thread i */
		if( pthread_create( &thread[i], NULL, philosopher, &id[i] ) != 0 ) {
			printf("ERROR: could not create thread%d\n", i );
			exit( EXIT_FAILURE );
		}
		else {
			printf("Philosopher %d born!\n", i );
		}
	}

    /* destroy semaphores */
    for( i = 0; i < 5; i++ ) {
        pthread_join( thread[ i ], NULL );
        sem_destroy( &gabel[ i ] );
    }

    printf("END\n");
	exit( EXIT_SUCCESS );
}
