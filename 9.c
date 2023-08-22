#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<time.h>

int main(int argc,char* argv[]){
	struct stat attr;
	//first argument is filename and second is pointer to object
	if(stat(argv[1],&attr)!=0)
		perror("stat() error");
	else{
		printf("file info: \n");
		printf("	inode: %d\n",(int)attr.st_ino);
		printf("	links: %ld\n",attr.st_nlink);
		printf("	uid:   %d\n",(int)attr.st_uid);
		printf("	gid:   %d\n",(int)attr.st_gid);
		printf("	size:  %ld\n",attr.st_size);
	}
		
return 0;
}
