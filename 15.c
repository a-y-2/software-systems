/*
15. Write a program to display the environmental variable of the user (use environ).

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

int main(int argc,char* argv[],char* envp[]){
	
	int i;
	for(i=0;envp[i]!=NULL;i++)
		printf("\n%s",envp[i]);
	getchar();
	
return 0;
}
