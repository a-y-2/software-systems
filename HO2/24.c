//24. Write a program to create a message queue and print the key and message queue id.
//AYUSHI PRASAD
//MT2023145

#include <sys/types.h>
#include <sys/ipc.h>   
#include <sys/msg.h>  
#include <stdio.h>     
#include <unistd.h>    

void main()
{
    key_t queueKey;      
    int queueIdentifier; 

    queueKey = ftok(".", 1);//to generate key (like fd for files)

    queueIdentifier = msgget(queueKey, IPC_CREAT | IPC_EXCL | 0700);//create a new message queue with the specified key
    queueIdentifier = msgget(queueKey,0);//return unique identifier for msg queue as now the key exists and msgflag=0

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n", queueIdentifier);
}