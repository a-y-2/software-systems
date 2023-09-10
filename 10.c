/*
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.

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
	int fd = open(argv[1],O_RDWR);
	int fd_read = open(argv[2],O_RDONLY);
	if(fd==-1||fd_read==-1)
		printf("useless");

	//start writing now

	char buf[10];
	int char_read = read(fd_read,&buf,10);
	int char_written = write(fd,&buf,10);
	int seek = lseek(fd,10,SEEK_CUR);
	write(fd,&buf,10);
	printf("%d",seek);
	int fd_read_close = close(fd_read);
	int fd_write_close = close(fd);
	
	if(fd_read_close==-1||fd_write_close==-1)
		printf("totally useless");

	return 0;
}
