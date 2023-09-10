/*
18. Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

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
	struct {
		int train_num;
		int ticket_count;
	}db;
	int fd,input;
	fd = open("record.txt",O_RDWR);
	printf("select train no. 1,2or3\n");
	scanf("%d",&input);
	
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = (input-1)*sizeof(db);
	//lock only seleted train's record
	lock.l_len = sizeof(db);
	lock.l_pid = getpid();
	//read value of ticket number	
	lseek(fd,(input-1)*sizeof(db),SEEK_SET);
	read(fd,&db,sizeof(db));
	printf("now entering critical section to modify ticket count\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("current ticket count: %d\n",db.ticket_count);
	db.ticket_count++;
	//now fd is pointing to end of current record and we have to move it to beginning of current record
	lseek(fd,-1*sizeof(db),SEEK_CUR);
	write(fd,&db,sizeof(db));
	printf("to book ticket press enter\n");
	getchar();
	getchar();
	lock.l_type = F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("ticket booked -- ticket number --> %d\n",db.ticket_count);
return 0;
}
