/*
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp

AYUSHI PRASAD
MT2023145
	*/

#include<unistd.h>

int main(){
	execl("/bin/ls","ls","-lr",NULL);
	return 0;
}
