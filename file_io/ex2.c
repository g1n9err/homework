#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#define SIZE 256

int main () {
    int fd;
    
    fd = open("./test.txt", O_RDONLY);
    if(fd == -1){
        perror("open");
        return 1;
    }
    char buffer[SIZE];
    read(fd,buffer,sizeof(buffer));
    write(1,buffer,sizeof(buffer));
    close(fd);
    printf("\n");
    return 0;
}
