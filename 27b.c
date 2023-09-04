#include<unistd.h>

int main(){
	execlp("ls","ls","-lr",NULL);
	return 0;
}
