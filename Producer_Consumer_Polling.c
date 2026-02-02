#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include <unistd.h>

pthread_mutex_t mtx;
int avail = 0;

void *producerFunc(void* arg){

    int toRequired = *((int *)arg);
    for(int i = 0; i < toRequired; i++){
        /*Gets the lock once lock is available*/
        pthread_mutex_lock(&mtx);

        avail++;
        /*Reales the lock after producing the result*/
        printf("Producer:%d\n", i+1);
        pthread_mutex_unlock(&mtx);
        usleep(100000);
    }
    //getchar();
    pthread_exit(NULL);


}
void *consumerFunc(void *arg){
    int toRequired = *((int *)arg);
    int numConsumed = 0;
    int done = 0;

    for(;;){
        /*Gets the lock once lock is available*/
        
        pthread_mutex_lock(&mtx);
        //printf("consumer gots the lock: %d\t%d\n", i, avail);
        

        /*Checkin whether the data is ready or not*/
        while(avail > 0){
            numConsumed++;
            avail--;
            printf("Consumer:%d\n", numConsumed);
            done = numConsumed >= toRequired;
            // printf("Consumer:%d\n", avail);
        }
        // avail--;
        // printf("Consumer:%d\n", avail);
        /*Reales the lock after producing the result*/
        pthread_mutex_unlock(&mtx);

        if(done)
            break;

    }



    pthread_exit(NULL);

}

int main(){

    pthread_t producer, consumer;
    int required = 20;

    printf("The pid is %d\n", getpid());

    int ret = pthread_create(&producer,NULL, producerFunc, &required);
    if(ret < 0){
        printf("Producer Thread creation failed with an error\n");
        
    }

    ret = pthread_create(&consumer,NULL, consumerFunc, &required);
    if(ret < 0){
        printf(" consumer Thread creation failed with an error\n");
        
    }

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    pthread_exit(NULL);
    
    return 0;
}