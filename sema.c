//C program to implement semaphores
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>

int shared = 0;
sem_t s;

void *fun1()
{
    int x=0;
    sem_wait(&s);
    x=shared;
    printf("Process 1 reads shared value as %d\n",x);
    x++;
    sleep(1);
    shared=x;
    printf("Process 1 writes shared value as %d\n",x);
    sleep(1);
    sem_post(&s);
}

void *fun2()
{
    int y=0;
    sem_wait(&s);
    y=shared;
    printf("Process 2 reads shared value as %d\n",y);
    y++;
    sleep(1);
    shared=y;
    printf("Process 2 writes shared value as %d\n",y);
    sleep(1);
    sem_post(&s);
}

void main()
{
    sem_init(&s,0,1);
    pthread_t thread1,thread2;
    for(int i=0;i<5;i++)
    {
        pthread_create(&thread1,NULL,fun1,NULL);
        pthread_create(&thread2,NULL,fun2,NULL);
        pthread_join(thread1,NULL);
        pthread_join(thread2,NULL);
    }
    printf("Final Value: %d",shared);
}