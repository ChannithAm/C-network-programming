#include "TCPEchoServer.h"  /* TCP echo server includes */
#include <sys/time.h>       /* for struct timeval {} */
#include <fcntl.h>          /* for fcntl() */
#include <ctype.h>          /* for toupper() */

#define RCVBUFSIZE 32 // size of receive buffer
#define MAXPENDING 5 // maximum of outstanding connection request

void DieWithError(char *errorMessage);  /* Error handling function */
void HandleTCPClient(int clntSocket);   /* TCP client handling function */
int CreateTCPServerSocket(unsigned short port); /* Create TCP server socket */
int AcceptTCPConnection(int servSock);  /* Accept TCP connection request */

int main(int argc, char const *argv[]) // argc: num of string ing argv
{
    
    int *servSock;                   /* Socket descriptors for server */
    int maxDescriptor;               /* Maximum socket descriptor value */
    fd_set sockSet;                  /* Set of socket descriptors for select() */
    long timeout;                    /* Timeout value given on command-line */
    struct timeval selTimeout;       /* Timeout for select() */
    int running = 1;                 /* 1 if server should be running; 0 otherwise */
    int noPorts;                     /* Number of port specified on command-line */
    int port;                        /* Looping variable for ports */
    unsigned short portNo;           /* Actual port number */

    if(argc < 3) // Test for correction number of arguments
    {
        fprintf(stderr, "Usage: %s  <Timeout (secs.)> <Port 1> <Port 2> <Port ..>\n",argv[0]);
        exit(1);
    }

    timeout = atol(argv[1]); // first arg: Timeout
    noPorts = argc - 2; // Number of ports is argument count minus 2
    //printf("noPort: %d", noPorts);
    
    // Allocate list of sockets for incomming connections
    servSock = (int*)malloc(noPorts * sizeof(int));

    // Initialize maxDescriptor for use by select()
    maxDescriptor = -1;

    // Create list of ports and sockets to handls ports
    for(port=0; port<noPorts; port++){
        // Add port to port list
        portNo = atoi(argv[port + 2]); // skip first two arguments

        // Create port socket
        servSock[port] = CreateTCPServerSocket(portNo);

        // Determine if new descriptor is the largest
        if(servSock[port] > maxDescriptor){
            maxDescriptor = servSock[port];
        }

    }

    printf("Starting server: Hit return to shutdown\n");
    while(running){
        // Zero socket descriptor vector and set for server sockets
        // This must be reset every time select () is called.
        FD_ZERO(&sockSet);

        // Add keyboard to descriptor vector
        FD_SET(STDIN_FILENO, &sockSet);
        for(port=0; port<noPorts; port++){
            FD_SET(servSock[port], &sockSet);
        }

        // Timeout specification
        // This must be reset every time select() is called
        selTimeout.tv_sec = timeout;    // timeout(secs.)
        selTimeout.tv_usec = 0;         // 0 microseconds

        // Suspend program until descriptor is ready or timeout
        if(select(maxDescriptor+1, &sockSet, NULL, NULL, &selTimeout) == 0){
            printf("No echo request for %1d secs... Server still alive\n", timeout);
        }
        else{
            if(FD_ISSET(0, &sockSet)){ // Check keyboard{
                printf("Shutting down server\n");
                getchar();
                running=0;
            }

            for(port=0; port<noPorts; port++){
                if(FD_ISSET(servSock[port], &sockSet)){
                    printf("Request on port %d: ", port);
                    HandleTCPClient(AcceptTCPConnection(servSock[port]));
                }
            }
        }
    }

    // Close sockets
    for (port=0; port<noPorts; port++){
        close(servSock[port]);
    }
    // Free list of sockets
    free(servSock);

    exit(0);
}

int AcceptTCPConnection(int servSock){

    int clntSock;     // Socket descriptor for client
    struct sockaddr_in echoClntAddr;    // Client address
    unsigned int clntLen;   // Length of client address data structure

    // Set the size of the in-out parameter
    clntLen = sizeof(echoClntAddr);

    // Wait for a client to connect
    if((clntSock = accept(servSock, (struct sockaddr*) &echoClntAddr, &clntLen)) < 0){
        DieWithError("accept() failed");
    }

    // clntSock is connected to a client!
    printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

    return clntSock;
}

int CreateTCPServerSocket(unsigned short port){
    int sock;   // socket to create
    struct sockaddr_in echoServerAddr; // local address

    // create socket for incoming connections
    if((sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        DieWithError("Socket() failed.");
    }

    // Construction local address structure
    memset(&echoServerAddr, 0, sizeof(echoServerAddr)); // Zero out structure
    echoServerAddr.sin_family = AF_INET;  // Internet address family
    echoServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incomming interface
    echoServerAddr.sin_port = htons(port); // local port

    // Bind to the local address
    if(bind(sock, (struct sockaddr*)&echoServerAddr, sizeof(echoServerAddr)) < 0){
        DieWithError("bind() failed.");
    }

    // Mark the socket so it will listen for incoming connections
    if(listen(sock, MAXPENDING) < 0){
        DieWithError("listen() failed");
    }

    return sock;
}

void HandleTCPClient(int clntSocket){
    
    int i;
    char echoBuffer[RCVBUFSIZE];    // Buffer for echo string
    int recvMsgSize;                // Size of received message

    // Receive message from client
    if((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0){
        DieWithError("recv() failed");
    }

    // Send received string and receive again until end of transmission
    while(recvMsgSize > 0)      // zero indicates end of transmission
    {
        for(i=0; echoBuffer[i]; i++){
            if(echoBuffer[i] == 'a' || echoBuffer[i] == 'e' || echoBuffer[i] == 'i' || 
                echoBuffer[i] == 'o' || echoBuffer[i] == 'u'){
                    echoBuffer[i] = toupper(echoBuffer);
                }
            else{
                echoBuffer[i] = echoBuffer[i];
            }
        }

        // Echo message back to client
        if(send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize){
            DieWithError("send() failed");
        }

        // See if there is more data to receive
        if((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0){
            DieWithError("recv() failed");
        }
    }

    close(clntSocket);  // Close client socket
}

void DieWithError(char *errorMessage){
    perror(errorMessage);
    exit(1);
}