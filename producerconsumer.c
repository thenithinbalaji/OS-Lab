#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdbool.h>

void * producer();
void * consumer();

sem_t mutex;
sem_t full;
sem_t empty;

int buffer[5];
int start = 0;
int end = 0;

int main(){
    pthread_t prod;
    pthread_t cons;
 
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,5);

    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    pthread_join(prod,NULL);
    pthread_join(cons,NULL);
    return 0;
}

void *producer(){
    while(1){
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("enter a value to produce :");
        int temp;
        scanf("%d",&temp);
        buffer[(start++)%5]=temp;
        sem_post(&mutex);
        sem_post(&full);

    }
}

void *consumer(){
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);
        int temp;
        temp=buffer[(end++)%5];
        printf("Consumed: %d\n", temp);
        sem_post(&mutex);
        sem_post(&empty);
    }
}