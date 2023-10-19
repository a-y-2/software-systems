#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd1,fd2;
	char buf1[100],buf2[100];
	fd1 = open("fifo1",O_RDONLY);
	fd2 = open("fifo2",O_WRONLY);
	
	read(fd1,buf1,sizeof(buf1));
	
	printf("\n text from fifo1 : %s \n",buf1);
	printf("\n enter text :\n");
	scanf("%[^\n]",buf2);
	write(fd2,buf2,sizeof(buf2));

  	return 0;
}
