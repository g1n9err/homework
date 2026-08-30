#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void)
{
    int server_fd, client_fd;
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    char buffer[BUFF_SIZE];
    char result[BUFF_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return -1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

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

    client_fd = accept(server_fd, (struct sockaddr *)&addr, &addrlen);
    if (client_fd < 0) {
        perror("accept");
        close(server_fd);
        return -1;
    }

    int bytes = recv(client_fd, buffer, BUFF_SIZE - 1, 0);
    if (bytes <= 0) {
        perror("recv");
        close(client_fd);
        close(server_fd);
        return -1;
    }

    buffer[bytes] = '\0';

    printf("Received: %s\n", buffer);

    double a, b, ans;
    char op;

    if (sscanf(buffer, "%lf %c %lf", &a, &op, &b) != 3) {
        strcpy(result, "Invalid expression");
    } else {
        switch (op) {
            case '+':
                ans = a + b;
                break;

            case '-':
                ans = a - b;
                break;

            case '*':
                ans = a * b;
                break;

            case '/':
                if (b == 0) {
                    strcpy(result, "Error: Division by zero");
                    send(client_fd, result, strlen(result), 0);
                    close(client_fd);
                    close(server_fd);
                    return 0;
                }
                ans = a / b;
                break;

            default:
                strcpy(result, "Invalid operator");
                send(client_fd, result, strlen(result), 0);
                close(client_fd);
                close(server_fd);
                return 0;
        }

        sprintf(result, "Result = %.2f", ans);
    }

    send(client_fd, result, strlen(result), 0);

    close(client_fd);
    close(server_fd);

    return 0;
}