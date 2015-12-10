#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void threadfunc( void* ptr )
{
    int id = *( ( int* ) ptr );
    printf("Helloo my thread id is %d\n", id );
}


int main()
{
    pthread_t tid[ 2 ];
    int        id[ ] = { 1, 2 };

    pthread_create(&tid[0], NULL, (void*(*)(void *))threadfunc, &id[0]);
    pthread_create(&tid[1], NULL, (void*(*)(void *))threadfunc, &id[1]);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
}
