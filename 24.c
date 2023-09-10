/*
24. Write a program to create an orphan process.

AYUSHI PRASAD
MT2023145
	*/

#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>

int main(){

	if(fork()==0){
		printf("\n child process id : %d",getpid());
		sleep(1);
		printf("\n child process id after becoming orphan :%d",getpid());
		while(1);
		}
	else{
		printf("\n parent process id : %d",getpid());
		exit(0);

	}
return 0;
}
