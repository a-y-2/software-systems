/*
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call

AYUSHI PRASAD
MT2023145
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd;
	fd=creat("lab3.txt",O_RDONLY);
	printf("%d",fd);
	return 0;
}
