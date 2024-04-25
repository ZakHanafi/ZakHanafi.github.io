#include <stdio.h>  
#include <sys/socket.h> 
#include <arpa/inet.h>  
#include <unistd.h>
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    int bytes_read;

    if (argc < 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        close(sock);
        return 1;
    }

    while ((bytes_read = read(sock, buffer, sizeof(buffer)-1)) > 0) {
        buffer[bytes_read] = '\0'; 
        printf("%s", buffer);
    }
    
    if (bytes_read < 0) {
        perror("Read failed");
    }

    close(sock);
    return 0;
}
