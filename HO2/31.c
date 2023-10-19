/*
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore

AYUSHI PRASAD
MT2023145
*/

#include <sys/types.h>
#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <unistd.h>    
#include <stdio.h>    

void main()
{
	int semkey=ftok("./bisemaphore",1);
	int sId = semget(semkey, 1, IPC_CREAT | 0777);

	  union semun {
        	int val;
    	 } semSet,bisemSet;
	  semSet.val=1;
	  bisemSet.val=4;

	  int Status = semctl(sId, 0, SETVAL, semSet);
	 int bisemkey=ftok("./semaphore",1);
	 int bisId= semget(bisemkey, 1, IPC_CREAT | 0777);
	 Status = semctl(bisId, 0, SETVAL, bisemSet);
	 
}