#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t chops[5];
void *philosopher(void *ind);
int main()
{
    int philno[] = {0, 1, 2, 3, 4};
    pthread_t phil[5];
    for (int i = 0; i < 5; i++)
    {
        sem_init(&chops[i], 0, 1);
    }
    for (int i = 0; i < 5; i++)
        pthread_create(&phil[i], NULL, philosopher, &philno[i]);
    pthread_exit(NULL);
    return 0;
}
void *philosopher(void *ind)
{
    int i = *(int *)ind;
    while (1)
    {
        printf("Phil %d hungry\n", i);
        sem_wait(&chops[i]);
        sem_wait(&chops[(i + 1) % 5]);
        printf("Phil %d takes the fork %d and %d\n", i,i, (i + 1) % 5);
        printf("Phil %d eating \n", i);
        sleep(2 + rand() % 3);
        printf("Phil %d puts down the fork %d and %d\n",i, i, (i + 1) % 5);
        sem_post(&chops[(i + 1) % 5]);
        sem_post(&chops[i]);

        printf("Phil %d thinking \n", i);
        sleep(rand() % 4);
    }
}