/*
21. Write two programs so that both can communicate by FIFO -Use two way communications.

AYUSHI PRASAD
MT2023145
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd1,fd2;
	char buf1[100],buf2[100];
	fd1 = open("fifo1",O_WRONLY);
	fd2 = open("fifo2",O_RDONLY);
	printf("\n enter the text \n");
	scanf("%[^\n]",buf1);
	write(fd1,buf1,sizeof(buf1));
	read(fd2,buf2,sizeof(buf2));
	printf("\n text from fifo2 : %s \n",buf2);


  	return 0;
}
