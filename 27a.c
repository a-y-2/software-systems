#include<unistd.h>

int main(){
	execl("/bin/ls","ls","-lr",NULL);
	return 0;
}
