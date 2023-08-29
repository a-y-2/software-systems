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
		int ticket_no;
	}db;

	db.ticket_no=1;
	//CREATE FILE db in RDWR mode and write to it the db structure which has ticket no.=1
  	fd = open("db",O_CREAT|O_RDWR,0744);
	write(fd,&db,sizeof(db));
	close(fd);
	//open db in read only mode and read db structure from it
	fd = open("db",O_RDONLY);
	read(fd,&db,sizeof(db));
	printf("ticket number : %d\n",db.ticket_no);
	close(fd);

return 0;
}
