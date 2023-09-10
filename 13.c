/*
13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).

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
	fd_set rfds;
	struct timeval tv;
	int ret;
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);
	tv.tv_sec=10;
	tv.tv_usec=0;
	ret=select(1,&rfds,NULL,NULL,&tv);
	if(ret==-1)
		perror("error");
	else if(ret)
		printf("data is available for reading within 10 seconds");
	else
		printf("data is not available for reading withn 10 seconds");

	
return 0;
}
