#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 50

int main() {
    int parent_child[2];
    int child_parent[2];
    pid_t pid;

    if (pipe(parent_child) == -1) {
        perror("pipe");
        return 1;
    }

    if (pipe(child_parent) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        const char *parent_msg = "Hello";
        char parent_buffer[SIZE];

        close(parent_child[0]);
        close(child_parent[1]);

        write(parent_child[1], parent_msg, strlen(parent_msg) + 1);

        read(child_parent[0], parent_buffer, sizeof(parent_buffer));
        printf("Parent received: %s\n", parent_buffer);

        close(parent_child[1]);
        close(child_parent[0]);

        wait(NULL);
    } else {
        const char *child_msg = "Thanks";
        char child_buffer[100];

        close(parent_child[1]);
        close(child_parent[0]);

        read(parent_child[0], child_buffer, sizeof(child_buffer));

        if (strcmp(child_buffer, "Hello") == 0) {
            write(child_parent[1], child_msg, strlen(child_msg) + 1);
        }

        close(parent_child[0]);
        close(child_parent[1]);

        return 0; 
    }

    return 0;
}
