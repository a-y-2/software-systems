#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	//lab2.txt should be existing and tempsoftlink should not exist
	int v = symlink("lab2.txt","tempsoftlink");
	if(v<0)
		{perror("failed");return 1;}
	int f=link("lab2.txt","temphardlink");
	if(f<0)
		{perror("failed");return 1;}
	//lab2.txt should not exist
	int m=mknod("lab2.txt",S_IFIFO,0);
	if(m<0)
		{perror("failed");return 1;}
	return 0;
}
