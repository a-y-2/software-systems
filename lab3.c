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
