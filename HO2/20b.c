#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	char buff[100];
	int fd = open("fifo20",O_RDONLY);
	read(fd,buff,sizeof(buff));
	printf("\n text from fifo file: %s\n",buff);
        
  	return 0;
}
