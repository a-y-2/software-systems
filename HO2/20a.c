/*
20. Write two programs so that both can communicate by FIFO -Use one way communication.

AYUSHI PRASAD
MT2023145
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	char buff[100];
	int fd = open("fifo20",O_WRONLY);
	printf("\n enter text : ");
	scanf("%[^\n]",buff);
	write(fd,buff,sizeof(buff));
        
  	return 0;
}
