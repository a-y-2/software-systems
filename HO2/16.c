/*
16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.

AYUSHI PRASAD
MT2023145
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char buf1[100],buf2[100];
	int fd1[2],fd2[2];
	pipe(fd1);
	pipe(fd2);
	
	if(!fork()){
		close(fd1[0]);//close read end of fd1 for child
		close(fd2[1]);//close write end of fd2 for child
		printf("enter message for parent : ");
		scanf(" %[^\n]",buf1);//read till newline encountered
		write(fd1[1],buf1,sizeof(buf1));
		read(fd2[0],buf2,sizeof(buf2));
		printf("message from parent: %s\n",buf2);
		}
	else{
		close(fd1[1]);
		close(fd2[0]);
		//child wrote into fd1 first,so read from fd1 first
		read(fd1[0],buf1,sizeof(buf1));
		printf("message from child: %s\n",buf1);
		printf("enter message to child: ");
		scanf("%[^\n]",buf2);
		write(fd2[1],buf2,sizeof(buf2));
	}


return 0;
}
