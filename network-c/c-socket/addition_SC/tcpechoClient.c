#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>

#define MAX_MSG 100
#define SERVER_ADDR "127.0.0.1"
#define CLIENT_ADDR "127.0.0.1"
#define SERVER_PORT 3786 
#define CLIENT_PORT 8229

int main(){
	int sd, rc, i, n;
	struct sockaddr_in clientAddr, servAddr;
	char line[MAX_MSG], line_r[MAX_MSG];

	/**************************************
	 * build server address structure
	 * *************************************/

	bzero((char *)&servAddr, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	servAddr.sin_port = htons(SERVER_PORT);

	/****************************************
	 * create stream socket
	 * *************************************/

	sd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Successfully create stream socket\n");

	/***************************************
	 * bind local port number
	 * ************************************/

	bind(sd, (struct sockaddr *)&clientAddr, sizeof(clientAddr));
	printf("Bound local port successfully\n");

	/*******************************************
	 * connect to server
	 * ***************************************/

	connect(sd, (struct sockaddr *)&servAddr, sizeof(servAddr));
	printf("Connect to server successfully\n");

	/****************************************
	 * send data to server 
	 * *************************************/

	do{
		printf("Enter string to send to server: ");
		scanf("%s", line);
		send(sd, line, strlen(line) + 1, 0);
		printf("Data sent (%s)\n", line);
		n = recv(sd, line_r, MAX_MSG, 0);
		line_r[n] = '\n';

		printf("Received from server [IP %s, TCP port %d]: %s\n",
				inet_ntoa(servAddr.sin_addr),
				ntohs(servAddr.sin_port), line_r);
	}while(strcmp(line, "quit"));

	printf("Closing connection with the server\n");
	close(sd);
}
