#include "client.h"

int main() {
    int client_fd;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    char expression[BUFFER_SIZE] = {0};

    fgets(expression, sizeof(expression), stdin);

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Socket creation error.\n");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address.\n");
        close(client_fd);
        return -1;
    }

    if (connect(client_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Connection Failed.\n");
        close(client_fd);
        return -1;
    }

    printf("Connected to %s:%d\n", SERVER_IP, PORT);
    printf("Expression: %s\n", expression);
    send(client_fd, expression, strlen(expression), 0);

    int bytes_recv = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_recv > 0) {
        buffer[bytes_recv] = '\0';
        printf("%s\n", buffer);
    } else {
        fprintf(stderr, "Failed to receive data from server.\n");
    }

    close(client_fd);

    return 0;
}
