/*
17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl

AYUSHI PRASAD
MT2023145
*/

#include <unistd.h>   
#include <sys/types.h>
#include <stdio.h>     
void main()
{
    int pipefd[2];
    int pipeSt;
    pipeSt=pipe(pipefd);
    if(fork())
    {
	close(0);
	dup(pipefd[0]);
	close(pipefd[1]);
	execl("/usr/bin/wc","wc",NULL);
    }
    else
    {	close(1);
        dup(pipefd[1]);
        close(pipefd[0]);
        execl("/usr/bin/ls","ls","-l",NULL);		
    }
}