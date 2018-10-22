#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG	100
#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 3786

int main(){
	int sd, newSd, cliLen, n;
	struct sockaddr_in cliAddr, serAddr;
	char line[MAX_MSG], line_r[MAX_MSG];

	/***********************************
	 * build server address structure
	 * ********************************/
	bzero((char *)&serAddr, sizeof(serAddr));
	serAddr.sin_family = AF_INET;
	serAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	serAddr.sin_port = htons(SERVER_PORT);

	/***********************************
	 * Create stream socket
	 * ********************************
	 * */
	sd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Successfully created stream socket\n");

	/****************************************
	 * Bind local port number
	 * ****************************************/
	bind(sd, (struct sockaddr *)&serAddr, sizeof(serAddr));
	printf("Bound local port successfully\n");

	/**************************************
	 * specify number of concurent
	 * clients to listen for
	 * *************************************/
	listen(sd, 5);

	while(1){
		printf("Waiting for client connection on port TCP %u\n", 
				SERVER_PORT);
		/******************************
		 * wait for client connection*/
		cliLen = sizeof(cliAddr);
		newSd = accept(sd, (struct sockaddr*)&cliAddr, &cliLen);
		printf("Received connection from host [IP %s, TCP port %d]\n",
				inet_ntoa(cliAddr.sin_addr), 
				ntohs(cliAddr.sin_port));

		/***********************************************
		 * wait for data from client
		 * ********************************************/
		do{
			memset(line, 0x0, MAX_MSG);

			n = recv(newSd, line, MAX_MSG, 0);
			line[n] = '\n';

			printf("Receive from host [IP %s, TCP port %d]: %s\n",
					inet_ntoa(cliAddr.sin_addr),
					ntohs(cliAddr.sin_port), line);
			strcpy(line_r, line);
			send(newSd, line_r, strlen(line_r) + 1, 0);
			printf("Data echoed (%s) \n", line_r);
		}while(abs(strcmp(line, "quit")));

		/**************************************
		 * close client connection
		 * **************************************/
		printf("Closing connection with host [IP %s, TCP port %d]\n",
				inet_ntoa(cliAddr.sin_addr),
				ntohs(cliAddr.sin_port));
		close(newSd);
	}

}
