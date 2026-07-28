#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

void *worker(void *arg)
{
    int id = *(int *)arg;

    printf("Thread %d started.\n", id);

    for (int i = 1; i <= 5; i++)
    {
        printf("Thread %d : Step %d\n", id, i);
        sleep(1);
    }

    printf("Thread %d finished.\n\n", id);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    printf("========== Multithreading Demonstration ==========\n\n");

    for (int i = 0; i < NUM_THREADS; i++)
    {
        ids[i] = i + 1;

        if (pthread_create(&threads[i], NULL, worker, &ids[i]) != 0)
        {
            printf("Failed to create thread %d\n", i + 1);
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed successfully.\n");

    return 0;
}
