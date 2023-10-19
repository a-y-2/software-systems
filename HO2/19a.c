/*
19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function

AYUSHI PRASAD
MT2023145
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
        // Create the FIFO using mknod
        if (mknod("fifo1", S_IFIFO | 0666, 0) == -1) {//last arg=device_special_number=0 since it is a pseudo device special file 
            perror("mknod");
            exit(EXIT_FAILURE);
        } else {
            printf("FIFO '%s' created successfully.\n");
        }


    return 0;
}
