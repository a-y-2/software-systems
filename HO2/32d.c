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
}