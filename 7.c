/*
7. Write a program to copy file1 into file2 ($cp file1 file2).

AYUSHI PRASAD
MT2023145
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	if(argc!=3)
		printf("you are useless!");
	int fd_read = open(argv[1],O_RDONLY);
	int fd_write = open(argv[2],O_WRONLY|O_CREAT,0744);
	if(fd_read==-1 || fd_write==-1)
		printf("useless");

	//start reading now
	while(1){
		char buf;
		int char_read = read(fd_read,&buf,1);
		if(char_read==0)//reached eof
			break;
		int char_written = write(fd_write,&buf,1);
	}

	int fd_read_close = close(fd_read);
	int fd_write_close = close(fd_write);

	if(fd_read_close==-1||fd_write_close==-1)
		printf("totally useless");

	return 0;
}
