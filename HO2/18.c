/*
18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

AYUSHI PRASAD
MT2023145
*/

#include <unistd.h>   
#include <sys/types.h>
#include <stdio.h>     
void main()
{
    int pipefd1[2];
    int pipefd2[2];
    int pipeSt1,pipeSt2;
    pipeSt1=pipe(pipefd1);
    pipeSt2=pipe(pipefd2);
    if(fork())
    {
	if(fork())
	{
		dup2(pipefd2[0],0);
		close(pipefd2[1]);
		 close(pipefd1[0]);
        	close(pipefd1[1]);
		execl("/usr/bin/wc","wc",NULL);
	}
	else
	{
		dup2(pipefd1[0],0);
        	close(pipefd1[1]);
		dup2(pipefd2[1],1);
		close(pipefd2[0]);
        execl("/usr/bin/grep","grep","^d",NULL);

	}
    }
    else
    {
        dup2(pipefd1[1],1);
        close(pipefd1[0]);
	close(pipefd2[0]);
	close(pipefd2[1]);
        execl("/usr/bin/ls","ls","-l",NULL);		
    }
}