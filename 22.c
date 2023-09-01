#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>

int main(){
	int fd;
	char buf='a';
	fd=open("22.txt",O_RDWR);
	if(fork()==0){
		printf("\n child process id : %d",getpid());
		printf("\n child is writing");
		write(fd,&buf,sizeof(buf));
	}
	else{
		printf("\n parent process id : %d",getpid());
		printf("\n parent is writing");
		write(fd,&buf,sizeof(buf));
	}
return 0;
}
