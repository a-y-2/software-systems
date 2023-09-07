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
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;//The l_whence field is set to SEEK_SET, indicating that the starting offset for the lock is relative to the beginning of the file.
	lock.l_start = 0;
	lock.l_len = 0;//the l_len field is set to 0, indicating that the lock covers the entire file.
	lock.l_pid = getpid();//The l_pid field is set to the current process's PID (Process ID).
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
