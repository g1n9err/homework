#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int main () {
    
    int fd[2];
    char *buffer[20];
    //ssize_t byte_read;
    const char *wr = "Hello Child!";
    
    if(pipe(fd) == -1){
        perror("pipe");
        return 1;
    }

    pid_t pid = fork(); 
    if(pid < 0) {
        perror("fork");
        return 1;
    }
    
    if(pid == 0) {
        close(fd[1]);
        read(fd[0],buffer,sizeof(buffer));
        printf("Received: %s\n", buffer);
        close(fd[0]);
    } else if (pid > 0){
        close(fd[0]);
        write(fd[1],wr,strlen(wr)+1);
        close(fd[1]);
    }

    return 0;
}
