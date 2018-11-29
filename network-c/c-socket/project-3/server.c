// socket()
#include <sys/types.h>
#include <sys/socket.h>
// inet_addr()
#include <netinet/in.h>
#include <arpa/inet.h>
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// select()
#include <sys/select.h>
// close()
#include <unistd.h>

int main(){

    // Create server socket
    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    // check error
    if(serverSocket == -1){
        perror("CREATE SOCKET");
        exit(0);
    }
    // binding to address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    // if run in LAN network
    // serverAddress.sin_addr.s_addr = inet_addr(address);
    socklen_t len = sizeof(struct sockaddr_in);
    int check = bind(serverSocket, (struct sockaddr*)&serverAddress, len);
    // check error
    if(check == -1){
        perror("BIND");
        exit(0);
    }

    // Server is listening for connection
    check = listen(serverSocket, 10); // client
    // check error
    if (check == -1){
        perror("LISTEN");
        exit(1);
    }

    /***************************************************
     * Moi client ket noi den server, neu duoc chap nhan
     * thi server se tao ra mot socket de giao tiep voi
     * client den khi 1 trong 2 ben dong.
     * 
     * Ta da biet den forking server (moi khi chap nhan
     * mot connect thi tao 1 process de xu ly no),
     * hoac interactive server (lien tuc) kiem tra xem 
     * co ket noi khong.
     * 
     * O day ta dung select(), no se nhin (watch) tren
     * nhieu desciptor, socket cung la 1 loai file 
     * descriptor de xem co su kien nao xay ra khong?
     * 
     * Co 3 loai su kien tren mot file descriptor ma ta
     * co xem xet la:
     *  - ready to read
     *  - ready to write
     *  - exception.
     * 
     * O day ta chi quan tam den ready to read, su kien
     * co 1 ket noi den server coi nhu la mot su kien
     * "ready to read" tren server Socket
     * 
     * Ta can co 1 tap chua cac socket
    */
   struct sockaddr_in clientAddress;
   len = sizeof(struct sockaddr_in);
   // tap reaadfds de check cac socket, 1 tap de luu lai 
   // nhung thay doi cua tap readfds.
   fd_set readfds;
   fd_set masterfds; 
   FD_ZERO(&masterfds);
   FD_ZERO(&readfds);
   // add serverSocket vao tap masterfds
   FD_SET(serverSocket, &masterfds);

   int max_fd = serverSocket;
   int i;
   struct timeval timeout;
   // server se lang nghe trong 90s,
   // neu tham so timeout = NULL thi
   // select se chay mai
   timeout.tv_sec = 90;
   timeout.tv_usec = 0;
   int n_select;
    do{
        // copy masterfds vao readfds de doi su kien
        memcpy(&readfds, &masterfds, sizeof(masterfds));
        n_select = select(max_fd+1, &readfds, NULL, NULL, NULL);
        // ham nay se block chuong trinh den khhi co 1 
        // su kien ready to read xay ra
        if(n_select < 0){
            perror("SELECT");
            exit(0);
        }
        else if(n_select == 0){
            printf("Time out\n");
        }
        else{
            // duyet tat ca cac socket den max_fd
            for(i=0; i<= max_fd; i++){
                // neu serverSock co su kien ready to read nghia la no co ket noi moi
                if(FD_ISSET(i, &readfds)){
                    // kiem tra xem socket co nen duoc dong sau khi xly khong
                    int close_fd = 0;
                    if(i == serverSocket){
                        // chap nhan ket noi do
                        int newCon = accept(serverSocket, (struct sockaddr*)&clientAddress, &len);
                        printf("New connection \n");

                        // them vao masterfds set de check su kien
                        FD_SET(newCon, &masterfds);
                        if(newCon > max_fd) max_fd = newCon;
                    }
                    else{
                        // Nhan du lieu hoac su kien dong ket noi tu client
                        char message[100];
                        printf("Receive data in socket %d \n", i);
                        int nrecv = recv(i, message, 100, 0);
                        if(nrecv == -1){
                            printf("In socket %d\n", i);
                            perror("RECEIVE");
                            close_fd = 1;
                        }
                        else if(nrecv != 0){
                            message[nrecv] = 0;
                            printf("Client say: %s\n", message);
                            // gui lai cho client
                            int nsent = send(i, message, strlen(message), 0);
                            if(nsent == -1){
                                printf("In socket %d\n", i);
                                perror("SEND");
                                close_fd = 1;
                            }
                        }
                        else{
                                close_fd = 1;
                        }
                    }
                    if(close_fd == 1){
                        FD_CLR(i, &masterfds);
                        close(i);
                    }
                }
            }
        }
    }while(1);
    return 0;
}