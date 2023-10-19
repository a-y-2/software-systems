#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>   
#include <unistd.h>    
#include <errno.h>
int main()
{
	struct msgbuf 
	{
		long mtype;
		int mtext;
	}msg1,msg2;
	msg1.mtype=1;
	msg2.mtype=2;
	int qkey=ftok("./MsgQue",1);
	int qId=msgget(qkey,0);
	printf("Key: %d\n", qkey);
    	printf("Message Queue Identifier: %d\n\n", qId);
	int msg=msgrcv( qId, &msg2 ,100,2,IPC_NOWAIT);
	printf("message from queue with IPC_NOWAIT flag %d\n",msg2.mtext);
	msg=msgrcv( qId, &msg1 ,100,1,0);
	printf("message from queue with 0 flag %d\n",msg1.mtext);
    return 0;
}