#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	if(argc!=2)
		printf("you are useless!");
	int fd_read = open(argv[1],O_RDONLY);
	//int fd_write = open(argv[2],O_WRONLY|O_CREAT,0744);
	//if(fd_read==-1 || fd_write==-1)
	//	printf("useless");

	//start reading now
	while(1){
		char buf;
//		int i=0;
		int char_read = read(fd_read,&buf,1);
		if(char_read==0)
			break;//reached eof
		if(buf==10)
			printf("\n");
		else
			printf("%c",buf);
//		i++;
		//int char_written = write(fd_write,&buf,1);
	}

	int fd_read_close = close(fd_read);
	//int fd_write_close = close(fd_write);

	//if(fd_read_close==-1||fd_write_close==-1)
	//	printf("totally useless");

	return 0;
}
