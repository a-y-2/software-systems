/*
30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory

AYUSHI PRASAD
MT2023145
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/shm.h> 
#include <unistd.h>    
#include <stdio.h> 

int main()
{
	char* spoint;
	char* stake;
	int skey=ftok("./shr",1);
	int sId=shmget(skey,100,IPC_CREAT|0766);

	 spoint=shmat(sId, (void *)0, 0);
	 sprintf(spoint,"hello world\n");

	 printf("Reading from the shared file:\n");
	 stake = shmat(sId, (void *)0, SHM_RDONLY);
	 printf("%s\n",stake);
	 getchar();

	 shmdt(spoint);
	 shmdt(stake);

	shmctl(sId , IPC_RMID, NULL);

}