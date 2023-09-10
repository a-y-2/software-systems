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
	int fd;
	struct {
	int train_number;
	int ticket_count;
	} db[3];

	for(int i=0;i<3;i++)
	{
		db[i].train_number=i+1;
		db[i].ticket_count=1;
	}


	fd=creat("record.txt",0744);
	write(fd,db,sizeof(db));
	close(fd);
	return 0;
}
	
