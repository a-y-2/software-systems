#include <sys/types.h>
#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <unistd.h>   
#include <stdio.h> 

void main()
{
	int semkey = ftok("./bisemaphore", 1);
	int semId=semget(semkey,0,0);

	 int semctlStatus = semctl(semId, 0, IPC_RMID);
}