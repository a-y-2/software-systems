/*
25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).

AYUSHI PRASAD
MT2023145
*/

#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>

int main(){
//The waitpid() system call suspends execution of the current process until a child specified by pid argument has changed state. 
//By default, waitpid() waits only for terminated children, but this behaviour is modifiable via the options argument
//on success, returns the process ID of the child whose state has changed; on error, -1 is returned
//A child that terminates, but has not been waited for becomes a "zombie".

//    pid: The process ID of the child process to wait for.
//    status: A pointer to an integer variable that will be set to the exit status of the child process.
//    options: A set of options that control the behavior of the waitpid() function.

	pid_t pid,pid1,pid2,pid3,input;
	int status;
	time_t t;
	if(fork()==0){
		pid1=getpid();
		printf("\n child1 process id : %d",pid1);
		}
	else{
		if(fork()==0){
		pid2=getpid();
		printf("\n child2 process id : %d",pid2);
		}
		else{
			if(fork()==0){
			pid3=getpid();
			printf("\n child3 process id : %d\n",pid3);
			}
			else{

			printf("\n which pid ?\n");
			scanf(" %d ",&input);
    				pid = waitpid(input,&status,0);
// Check the exit status of the terminated child process.
//The status argument is set to the exit status of the child process. The exit status is a number that can be used to 
//determine how the child process terminated.

				if(status)
					printf("child has exited with exit status %d\n",status);
				else
					printf("error\n");
   			 }
		}
	}
return 0;
}
