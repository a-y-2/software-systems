/*
21. Write a program, call fork and print the parent and child process id.

AYUSHI PRASAD
MT2023145
	*/

#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>

int main(){
	if(fork()==0)
		printf("\n child process id : %d",getpid());
	else
		printf("\n parent process id : %d",getpid());
return 0;
}
