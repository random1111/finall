#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<semaphore.h>

sem_t fork1[5];
sem_t room;
int cnt[5]={0};

void *philosopher(void *var)
{

	int j=*(int *)var;
	while(cnt[j]<3)
	{
		
		printf("Philosopher %d is thinking!\n",j);
		sleep(2);

		sem_wait(&room);		
		sem_wait(&fork1[j]);
		sem_wait(&fork1[(j+1)%5]);
		
		printf("Philosopher %d is eating!\n",j);
		sleep(2);
		cnt[j]=cnt[j]+1;
		
		sem_post(&fork1[(j+1)%5]);
		sem_post(&fork1[j]);
		sem_post(&room);
		printf("Philosopher %d is exiting\n",j);
				
	}	
	pthread_exit(NULL);
}

main()
{
	pthread_t pid[5];
	int a[5],i;
	
	for(i=0;i<5;i++)                                //semaphore initialise
	{
		sem_init(&fork1[i],0,1);
	}
	sem_init(&room,0,4);

	for(i=0;i<5;i++)                                //pthread create
	{
		a[i]=i;
		pthread_create(&pid[i],NULL,philosopher,&a[i]);
	}
	for(i=0;i<5;i++)                                 //pthread join
	{
		pthread_join(pid[i],NULL);
	}

	for(i=0;i<5;i++)                                  //semaphore destroy
	sem_destroy(&fork1[i]);
	sem_destroy(&room);
}
