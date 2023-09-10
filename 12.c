/*
12. Write a program to find out the opening mode of a file. Use fcntl.

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

int main(int argc,char* argv[]){
	
	int fd = open(argv[1],O_RDWR);
	int f = fcntl(fd,F_GETFL);
	if(f&O_RDWR)
		printf("read-write mode");
	else
		printf("not in read-write mode");

	close(fd);
	
return 0;
}
