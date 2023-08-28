#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd1,fd2,fd3,fd4,fd5;
	fd1=creat("lab5_1.txt",O_RDWR);
	fd2=creat("lab5_2.txt",O_RDWR);
	fd3=creat("lab5_3.txt",O_RDWR);
	fd4=creat("lab5_4.txt",O_RDWR);
	fd5=creat("lab5_5.txt",O_RDWR);
	while(1);
	return 0;
}
