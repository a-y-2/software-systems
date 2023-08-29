#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>

int main(){
	struct{
		int ticket_no;
	}db;
	struct flock lock;
	int fd;
	fd = open("db",O_RDWR);
	printf("before entering into critical section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("inside CS\N");
	
	read(fd,&db,sizeof(db));
	printf("current ticket no. : %d\n",db.ticket_no);
	db.ticket_no++;
	lseek(fd,0,SEEK_SET);
	write(fd,&db,sizeof(db));
	printf("press enter to unlock\n");
	getchar();
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("end of critical section");
return 0;
}
