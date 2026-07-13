#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h> 
#define SIZE 20
int main () {
    int fd[2];
    char buffer[20] = "Hello child";
    char ch;
    pipe(fd);
    close(fd[0]);
    char buffer[10] = "Hello child";
    write(fd[1], buffer, 10);
    printf("After write\n");

    printf("%s\n", buffer);

}
