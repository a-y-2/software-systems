/*
17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

AYUSHI PRASAD
MT2023145
	*/

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
