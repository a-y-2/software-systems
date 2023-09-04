#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *ch[]={"ls","-lr",NULL};
    	execv("/bin/ls",ch);
    	return 0;
}
