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
	
