/*
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore

AYUSHI PRASAD
MT2023145
*/

#include <sys/ipc.h>  
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     
int main()
{
	int i,k;
	char* st="./ticket";
	int semkey = ftok("./bisemaphore", 1);
	int semId=semget(semkey,0,0);
	
	struct sembuf sem;
	sem.sem_num=0;
	sem.sem_flg=0;
	sem.sem_op=-1;
	
	int stat=semop(semId, &sem, 1);

	i=open(st, O_RDWR);
	read(i,&k,sizeof(int));
	printf("ticket no.: %d\n",k);
	lseek(i,0,SEEK_SET);
	k=k+1;
	write(i,&k,sizeof(int));
	
	sem.sem_op=1;
	stat=semop(semId, &sem, 1);

}