#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>   
#include <unistd.h>    
#include <errno.h>

int main()
{
	int qkey=ftok("./MsgQue",1);
	int qId=msgget(qkey,0);
	printf("Key: %d\n", qkey);
    	printf("Message Queue Identifier: %d\n\n", qId);
	int msg_qstat=  msgctl(qId, IPC_RMID, NULL);
    return 0;
}