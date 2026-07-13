#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    
    if(pid < 0){
        perror("fork");
        return 1;
    }
    
    if(pid == 0) {
        exit(33);
    } else {
        int status;
        wait(&status);

        if(WIFEXITED(status)) {
            printf("Child exited whit status %d\n", WEXITSTATUS(status));
        }
    }

    printf("\n");
    
    return 0;
}