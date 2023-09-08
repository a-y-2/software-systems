/*
6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

AYUSHI PRASAD
MT2023145
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	int buf;
	//array is also correct
	int x;
	x=read(0,&buf,2);//if buf is array then remove & , 2 is size of int
	//we can also use 'sizeof' 
	printf("value entered:\n");	         
        write(1,&buf,x);
	
	

	return 0;
}
