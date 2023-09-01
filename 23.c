#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>

int main(){

	if(fork()==0){
		printf("\n child process id : %d",getpid());
		}
	else{
		printf("\n parent process id : %d",getpid());
		sleep(40);//so that till it sleeps we can check process status of child in other terminal
		wait(0);
	}
return 0;
}
