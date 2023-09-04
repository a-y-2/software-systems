#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    execle("/bin/ls","ls","-lr", NULL,NULL);
    return 0;
}
