#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define SHMSZ 27

main()
{
	
	int shmid;
	key_t key;
	char *shm = NULL, *s = NULL;
	
	key=5678;
	
	if((shmid=shmget(key,SHMSZ,IPC_CREAT | 0666))<0)
	{
			perror("shmgt");
			exit(1);
	}
	
	if((shm=shmat(shmid,NULL,0))==(char*)-1)
	{
		perror("shmat");
		exit(1);
	}
	
	s=shm;
	printf("\nEnter the message to send to the client");
	gets(s);
	
	while(*shm!='*')
		sleep(1);
	exit(0);
}
