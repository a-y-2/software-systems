#include <sys/ipc.h>  
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     


int main()
{
	char* st="./ticket";
	int i,k;
	int semkey = ftok("./bisemaphore", 1);
	int semId=semget(semkey,0,0);

	struct sembuf sem;
	sem.sem_num=0;
	sem.sem_flg=0;
	sem.sem_op=-1;
	int stat=semop(semId, &sem, 1);

	i=open(st, O_RDWR);
	printf("\ninsert the ticket number\n");
	scanf("%d",&k);
	write(i,&k,sizeof(int));
	
	sem.sem_op=1;
	stat=semop(semId, &sem, 1);

	close(i);
}