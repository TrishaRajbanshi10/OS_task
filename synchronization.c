#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3
#define INCREMENTS 100000

int counter = 0;

/* Mutex lock */
pthread_mutex_t lock;

void *increment(void *arg)
{
    int id = *(int *)arg;

    for(int i = 0; i < INCREMENTS; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;

        pthread_mutex_unlock(&lock);
    }

    printf("Thread %d completed.\n", id);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    printf("===== Thread Synchronization Using Mutex =====\n\n");

    for(int i = 0; i < NUM_THREADS; i++)
    {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, increment, &ids[i]);
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("\nExpected Counter Value : %d\n", NUM_THREADS * INCREMENTS);
    printf("Actual Counter Value   : %d\n", counter);

    return 0;
}
