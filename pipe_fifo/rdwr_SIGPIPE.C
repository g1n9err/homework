#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int main() {

    signal(SIGPIPE, SIG_IGN);

    int fd[2];

    pipe(fd);
   
    close(fd[0]);

    char buffer[10] = "hello";

    write(fd[1], buffer, 10);

    if (errno == EPIPE) {
        puts("EPIPE signal");
        exit(1);
    }
   
    printf("After write\n");

    printf("%s\n", buffer);

    
}