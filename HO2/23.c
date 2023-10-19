//Ayushi Prasad
//MT2023145


//23. Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
#include <unistd.h>   
#include <sys/types.h>
#include <sys/stat.h>  
#include <stdio.h>    
#include <errno.h>
#include<fcntl.h>
int main()
{
	char* fn="./queue";
	int mF = sysconf(_SC_OPEN_MAX);
	int sop =pathconf(fn, _PC_PIPE_BUF);
	printf("Maximum number of files that can be opened within the process: %d\n",mF);
	printf("Maximum size of a FIFO file: %d\n",sop);
}