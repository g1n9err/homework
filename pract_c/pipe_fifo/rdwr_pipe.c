#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    
    pipe(fd);
    
    char buffer[10] = "Hello";
    write(fd[1],buffer,10);
    
    char buf[10];
    read(fd[0],buf,10);
    
    printf("%s\n", buf);

    return 0;   
}
