#include <unistd.h>   
#include <sys/types.h>
#include <stdio.h>    
#include <fcntl.h>

void main()
{
    int pipefd[2];
    int pipeSt;
    pipeSt=pipe(pipefd);
    if(fork())
    {
	close(0);
	fcntl(pipefd[0], F_DUPFD,0);
	close(pipefd[1]);
	execl("/usr/bin/wc","wc",NULL);
    }
    else
    {	close(1);
        fcntl(pipefd[1], F_DUPFD,1);
        close(pipefd[0]);
        execl("/usr/bin/ls","ls","-l",NULL);		
    }
}