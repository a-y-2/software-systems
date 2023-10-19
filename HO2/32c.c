
#include <sys/ipc.h>  
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>    
#include <sys/shm.h>

int main()
{
	char* spoint;
	char* stake;
	int skey=ftok("./shr",1);
	int sId=shmget(skey,0,0);
	int val;
	int semkey = ftok("./bisemaphore", 1);
	int semId=semget(semkey,0,0);
	
	struct sembuf sem;
	sem.sem_num=0;
	sem.sem_flg=0;
	sem.sem_op=-1;
	
	int stat=semop(semId, &sem, 1);


	spoint=shmat(sId, (void *)0, 0);
	printf("enter number in shared memory:\n");
	scanf("%d",&val);
	 sprintf(spoint,"%d\n",val);

	 sem.sem_op=1;
	stat=semop(semId, &sem, 1);

	 printf("Reading from the shared file:\n");
	 stake = shmat(sId, (void *)0, SHM_RDONLY);
	 printf("%s\n",stake);

	 shmdt(spoint);
	 shmdt(stake);

}