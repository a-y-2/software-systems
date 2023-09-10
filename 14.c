/*
14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.

AYUSHI PRASAD
MT2023145
*/

#include<stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<fcntl.h>

int main(int argc, char **argv){
	if(argc > 1){
		int i = 1;
		while(--argc > 0){
			struct stat inf;//declare struct stat variable

			//call lstat function to get status of file;returns 0 on success
			int stats = lstat(argv[i], &inf);
			printf("%s\n", argv[i]);//print filename
			i++;
			printf("File Type :  ");

			//S_IFMT is a bit mask that is used to extract the file type from the st_mode field of the struct stat structure.
			switch(inf.st_mode & S_IFMT){
				case S_IFBLK: printf("Block Device\n"); 
							  break;
				case S_IFCHR: printf("Character Device\n");
							  break;
				case S_IFDIR: printf("Directory\n");
							  break;
				case S_IFIFO: printf("FIFO/pipe\n");
							  break;
				case S_IFLNK: printf("SymLink\n");
							  break;			  
				case S_IFREG: printf("Regular File\n");
							  break;
				case S_IFSOCK: printf("Socket\n");
							  break;
				default: 	  printf("Unknown File\n");
						 	  break;			  			  
			
			}
		}
	}
	else{
		printf("Give the command line arguments");
	}
	
	return 0;
}
