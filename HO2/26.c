/*
26. Write a program to send messages to the message queue. Check $ipcs -q
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
	struct msg 
	{
		long int mtype;//msg id
		char message[100];//pointer to msg text
	}myq;
	int key=ftok(".",1);
	int mqid=msgget(key,0);
	printf("\n enter message type :");
	scanf("%ld",&myq.mtype);
	printf("\n enter message :");
	scanf("%[^\n]",myq.message);
	int size = strlen(myq.message);
	printf("Key: %d\n", key);
    	printf("Message Queue Identifier: %d\n\n", mqid);
	int msg=msgsnd( mqid, &myq ,size+1, 0);
    return 0;
}