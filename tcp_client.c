

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    send(sockfd, "Hello Server, i am ansh", strlen("Hello Server, i am ansh"), 0);

    recv(sockfd, buffer, 1024, 0);
    printf("Server: %s\n", buffer);

    close(sockfd);
}
