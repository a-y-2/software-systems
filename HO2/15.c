/*
15. Write a simple program to send some data from parent to the child process.

AYUSHI PRASAD
MT2023145
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char buf[100];
	int fd[2];
	pipe(fd);

	if(fork()){
		close(fd[0]);//close read end for parent
		printf("enter message for child : ");
		scanf(" %[^\n]",buf);//read till newline encountered
		write(fd[1],buf,sizeof(buf));
		}
	else{
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("message from parent: %s\n",buf);
	}
	wait(0);//wait till all children have terminated

return 0;
}
