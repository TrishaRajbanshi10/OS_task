#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3
#define ITERATIONS 100000

int counter = 0;

void *increment(void *arg)
{
    int id = *(int *)arg;

    for(int i = 0; i < ITERATIONS; i++)
    {
        // No mutex protection
        counter++;
    }

    printf("Thread %d completed.\n", id);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    printf("===== Race Condition Demonstration =====\n\n");

    for(int i = 0; i < NUM_THREADS; i++)
    {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, increment, &ids[i]);
    }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nExpected Counter Value : %d\n", NUM_THREADS * ITERATIONS);
    printf("Actual Counter Value   : %d\n", counter);

    return 0;
}
