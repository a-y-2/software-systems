/*
14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

AYUSHI PRASAD
MT2023145
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int i , j , fd[2];
	char buf[50];
	i = pipe(fd);
	j = write(fd[1],"ss viva!\n",17);
	read(fd[0],buf,j);
	printf("from pipe : %s\n",buf);

return 0;
}
