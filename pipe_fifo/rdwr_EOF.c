#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



int main() {
    
    int fd[2];
    
    pipe(fd);
    int pid = fork();

    if(pid == 0) { //child
        char buf[10];
        
        close(fd[1]);
        
        while(1) {
            int n = read(fd[0],buf,10);
            if(n == 0);
                exit(1);
        }
        printf("%s\n", buf);
    } else  { //parent

        char buffer[10] = "Hello";
        close(fd[0]);
        
        write(fd[1],buffer,10);
        close(fd[1]);
        
        wait(NULL);
    }

    return 0;   
}
