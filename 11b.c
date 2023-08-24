#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>

int main(int argc,char* argv[]){
	int fd_read = open(argv[1],O_RDONLY);
	int fd_write = open(argv[2],O_RDWR);
	if(fd_read==-1||fd_write==-1)
		printf("useless");

	//start reading
	char buf[10];
	int char_read = read(fd_read,&buf,10);
	int char_write = write(fd_write,&buf,10);

	//now do the same with duplicate fd
	int fd_dup;
	 dup2(fd_write,10);
	char buff[10];
	int c_read = read(fd_read,&buff,10);
	int c_write = write(10,&buff,10);
	
	int x = close(fd_read);
	int y = close(fd_write);
	int z = close(fd_dup);
	
return 0;
}
