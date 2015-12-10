#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile int account = 0;

// global Mutex
pthread_mutex_t mutex;


void threadfunc( void* ptr )
{
    int id = *( ( int* ) ptr );
    int lsum = 0;
    int i;

    //meu
    //int a= pthread_mutex_init( mutex, NULL);
    printf("Hello! Thread %d here.\n", id );

    for( i = 0; i < 20000; i++ ) {
        int value = rand() % 5;
        lsum += value;

        //TODO: fix the issue ...
        pthread_mutex_lock(&mutex);
        account += value;
        pthread_mutex_unlock(&mutex);



        usleep( rand() % 100 );

    }

    //meu
    //int a= pthread_mutex_destroy(mutex);

    printf("Added %d units.\n", lsum );
}


int main()
{
    pthread_t tid[ 2 ];
    int        id[ ] = { 1, 2 };

    srand( time( NULL ) );

    // TODO: initalize mutex
    pthread_mutex_init(&mutex, NULL);


    pthread_create( &tid[ 0 ], NULL, ( void *(*)(void *) ) threadfunc, &id[ 0 ] );
    pthread_create( &tid[ 1 ], NULL, ( void *(*)(void *) ) threadfunc, &id[ 1 ] );

    pthread_join( tid[ 0 ], NULL );
    pthread_join( tid[ 1 ], NULL );

    // TODO: destroy mutex
    pthread_mutex_destroy(&mutex);

    printf( "Account: %d\n", account );
    return 0;
}
