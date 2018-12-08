// socket()
#include <sys/types.h>
#include <sys/socket.h>
// inet_addr()
#include <netinet/in.h>
#include <arpa/inet.h>
// 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    char* serverIP;
    unsigned short serverPort;
    if(argc <3 || argc >4){
        printf("Usage: %s serverIP serverPort", argv[0]);
        exit(1);
    }
    serverIP = argv[1];
    serverPort = atoi(argv[2]);
    printf("Server information: IP=%s Port=%d\n", serverIP, serverPort);
    // create TCP socket
    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // check error
    if(clientSocket == -1){
        perror("CREAT_SOCKET");
        exit(0);
    }

    // to connect to a server, firs we must have its address
    // de truyen dia chi ta can mot cau truc
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET; // Address family
    serverAddress.sin_port = htons(serverPort); // Port
    // in localhost case
    //serverAddress.sin_addr.s_addr = INADDR_ANY;
    // if we want to use internet, we must change to
    serverAddress.sin_addr.s_addr = inet_addr(serverIP);
    // 'address' is the same netmask

    // size of address
    socklen_t len = sizeof(struct sockaddr_in);

    // connect to server
    int check = connect(clientSocket, (struct sockaddr*)&serverAddress, len);
    // check error
    if(check == -1){
        perror("CONNECT");
        exit(0);
    }

    /**************************************************
     * Transceiver data between client and server
     * ************************************************
    */
   // send a message to server
   char message[100];
   strcpy(message, "Hi server");
   do{
       printf("Message: ");
       gets(message);
       int n_sent = send(clientSocket, message, strlen(message), 0);
       // check error
       if(n_sent == -1){
           perror("SEND");
           exit(0);
       }
       printf("Sent %d bytes to server\n", n_sent);
       printf("Waiting for reply...\n");
       // wait for server reply
       int n_recv = recv(clientSocket, message, 100, 0);
       // check error
       if(n_recv == -1){
           perror("RECEIVE");
           exit(0);
       }
       if(n_recv == 0){
           break;
       }
       message[n_recv] = 0;
       printf("Received string << %s >> with length: %d\n", message, n_recv);
   }while(1);
   close(clientSocket);
   return 0;
}
