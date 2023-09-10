/*
16. Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock

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
	int fd;
	struct flock lock;
	
	fd = open(argv[1],O_RDWR);
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	printf("before entering into critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("inside critical section\n");
	printf("press enter to unlock\n");
	getchar();
	printf("unlocked\n");
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("end");
		
return 0;
}
