/*
22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.

AYUSHI PRASAD
MT2023145
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>

int main() {
	fd_set rfds;//fd_Set represents fd sets for select system call ; it is a bit array
	struct timeval tv;
	tv.tv_sec = 40;
	

	int fd,fd1,fd2;
	char buf1[100],buf2[100];
	fd = open("fifo1",O_RDONLY);
	FD_ZERO(&rfds);//initialize all fds to zero
	FD_SET(fd,&rfds);//we are monitoring fifo1

	if(!select(fd + 1, &rfds, NULL, NULL, &tv))// nfds = 1+highest fd value , 
		printf("no data available\n");
	else{
		printf("\n data available for reading within 40 seconds\n");
		read(fd,buf1,sizeof(buf1));
		printf("\n data from fifo: %s\n",buf1);
	}

  	return 0;
}
/*To test the program, you can open another terminal window and write some data to the named pipe using a command like this:

echo "Hello, FIFO!" > fifo1

If you do this while the program is waiting, it should detect the data, read it, and display it.
*/
