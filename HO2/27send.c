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
	msg1.mtext=546;
	msg2.mtype=2;
    msg2.mtext=248;
	
	printf("%lu %lu\n",sizeof(msg1.mtext),sizeof(msg2.mtext));

	int qkey=ftok("./MsgQue",1);
	int qId=msgget(qkey,0);
	printf("Key: %d\n", qkey);
    	printf("Message Queue Identifier: %d\n\n", qId);
	
	int msg=msgsnd( qId, &msg1 ,sizeof(msg1.mtext), 0);
	msg=msgsnd( qId, &msg2 ,sizeof(msg2.mtext), 0);
    return 0;
}