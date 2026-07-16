#include <stdio.h>
#include <unistd.h>
#include <sys/term.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main () {
    int fd;
    fd = open("./hello.txt",O_CREAT | O_TRUNC | O_WRONLY, 0664);
    if(frd == -1){
        perror("open");
        return 1;
    }
    
    const char* buffer = "Hello C++ 2.4!"
    
    write(fd,buf,strlen(buffer)+1); 
    
    close(fd);
    return 0;
}
