#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int avail = 0;
pthread_mutex_t mtx;

sem_t wflag;
sem_t flag;

void *producerFunc(void *arg)
{
    int argValue = *(int*)arg;

    for(int i = 0; i < argValue; i++)
    {
        sem_wait(&flag);
        //printf("Producer waiting for lock\n");
        pthread_mutex_lock(&mtx);
        avail++;
        printf("Producer:%d\n", avail);
        pthread_mutex_unlock(&mtx);
        sem_post(&wflag);
        sleep(1);
    }
    return NULL;

}

void *consumerFunc(void *arg)
{
    int argValue = *(int*)arg;

    for(int i = 0; i < argValue; i++)
    {
        sem_wait(&wflag);
        //printf("Producer waiting for lock\n");
        pthread_mutex_lock(&mtx);
        avail--;
        printf("Consumer:%d\n", avail);
        pthread_mutex_unlock(&mtx);
        sem_post(&flag);
        
    }
    
    return NULL;

}

int main()
{
    pthread_t consumerThread, producerThread;
    int numberRequired = 5;

    
    sem_init(&wflag, 0, 0);
    sem_init(&flag, 0, 1);

    int ret = pthread_create(&producerThread, NULL, producerFunc, &numberRequired);
    if(ret > 0){
        printf("Producer thread got failed while creating\n");
    }


    ret = pthread_create(&consumerThread, NULL, consumerFunc, &numberRequired);
    if(ret > 0){
        printf("Consumer thread got failed while creating\n");
    }

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);
    return 0;
}