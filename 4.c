#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	int fd1,fd2;
	fd1=open("srcfile",O_RDWR);
	fd2=open("srcfile",O_CREAT|O_EXCL,O_RDWR);
	 
	printf("file descriptor of file1:%d , of file2: %d\n",fd1,fd2);	         
        

	
	

	return 0;
}
