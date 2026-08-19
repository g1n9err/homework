#include "server.h"
#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main () {
    int server_fd; 
    int client_fd;
    struct sockaddr_in addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(server_fd);
        return -1;
    }

    if (listen(server_fd, 1) < 0) {
        perror("listen");
        close(server_fd);
        return -1;
    }

    printf("Waiting for client...\n");

    socklen_t addrlen = sizeof(addr);

    client_fd = accept(server_fd, (struct sockaddr *)&addr, &addrlen);
    if (client_fd < 0) {
        perror("accept");
        close(server_fd);
        return -1;
    }

    while (1) {
        char password_buffer[PASSWORD_BUFFER];
        int bytes = recv(client_fd, password_buffer, sizeof(password_buffer) - 1, 0);
        password_buffer[bytes] = '\0';

        if (strcmp(password_buffer, "exit") == 0) {
            close(client_fd);
            break; 
        }

        if (strcmp(password_buffer, PASSWORD) == 0) {
            send(client_fd, "ACCESS GRANTED", strlen("ACCESS GRANTED"), 0);
            break;  
        } else {
            send(client_fd, "ACCESS DENIED", strlen("ACCESS DENIED"), 0);        
        }
    }
    close(client_fd);

    return 0;
}