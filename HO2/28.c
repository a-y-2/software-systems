/*
28. Write a program to change the exiting message queue permission. (use msqid_ds structure)

AYUSHI PRASAD
MT2023145
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>   
#include <unistd.h>    
#include <errno.h>

int main()
{
	struct msqid_ds mqI;
	int qkey=ftok("./MsgQue",1);
	int qId=msgget(qkey,0);
	printf("Key: %d\n", qkey);
    printf("Message Queue Identifier: %d\n\n", qId);
	int msg_qstat=  msgctl(qId, IPC_STAT, &mqI);
	mqI.msg_perm.mode=0666;
	msg_qstat=  msgctl(qId, IPC_SET, &mqI);
    return 0;
}