#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    socklen_t addr_size = sizeof(serverAddr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    sendto(sockfd, "Hello UDP Server, I am ansh", 30, 0,
           (struct sockaddr*)&serverAddr, addr_size);

    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&serverAddr, &addr_size);

    printf("Server: %s\n", buffer);

    close(sockfd);
}
