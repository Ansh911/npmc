#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(sockfd, 3);

    printf("Server listening...\n");
    socklen_t addr_size = sizeof(clientAddr);
    newSocket = accept(sockfd, (struct sockaddr*)&clientAddr, &addr_size);

    recv(newSocket, buffer, 1024, 0);
    printf("Client: %s\n", buffer);

    send(newSocket, "Hello from server", 18, 0);

    close(newSocket);
    close(sockfd);
}
