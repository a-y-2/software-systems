#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
        // Create the FIFO using mkfifo
        if (mkfifo("fifo2", 0666) == -1) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        } else {
            printf("FIFO created successfully.\n");
        }
  	return 0;
}
