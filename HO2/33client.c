/*
33. Write a program to communicate between two machines using socket.

AYUSHI PRASAD
MT2023145
*/

#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/ip.h>
#include <stdio.h>      
#include <unistd.h>   

void main()
{
	int soc=socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	char data[100];

	addr.sin_addr.s_addr = htonl(INADDR_ANY);
    	addr.sin_family = AF_INET;
    	addr.sin_port = htons(5050);
	int con = connect(soc,(struct sockaddr*)&addr, sizeof(addr));

	printf("Client to Server Connection successfully established\n");

	int rB = read(soc, data, 50);
	printf("%s\n",data);
	char send[20]="this is the client!";
	int wB = write(soc, send, 20);
	close(soc);
}