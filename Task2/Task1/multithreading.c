#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

pthread_mutex_t lock;
int counter = 0;

void *worker(void *arg)
{
    int id = *(int *)arg;

    for (int i = 1; i <= 5; i++)
    {
        pthread_mutex_lock(&lock);

        counter++;

        printf("Thread %d -> Stage %d | Counter = %d\n",
               id, i, counter);

        pthread_mutex_unlock(&lock);

        sleep(1);
    }

    printf("Thread %d Finished.\n", id);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int id[NUM_THREADS];

    pthread_mutex_init(&lock, NULL);

    printf("===== Multithreading Demonstration =====\n\n");

    for (int i = 0; i < NUM_THREADS; i++)
    {
        id[i] = i + 1;

        if (pthread_create(&threads[i], NULL, worker, &id[i]) != 0)
        {
            printf("Thread Creation Failed\n");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("\nAll Threads Completed Successfully.\n");
    printf("Final Counter Value = %d\n", counter);

    return 0;
}
