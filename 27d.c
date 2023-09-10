/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp

AYUSHI PRASAD
MT2023145
	*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *ch[]={"ls","-lr",NULL};
    	execv("/bin/ls",ch);
    	return 0;
}
