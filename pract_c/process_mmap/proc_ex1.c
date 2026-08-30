#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    
    if(pid < 0){
        perror("fork");
        return 1;
    }
    
    if(pid == 0) {
        printf("Hello From Child Process  %d\n ", getpid());
    } else {
        printf("Hello From Parent Process %d\n",getpid());
    }
    printf("\n");
    return 0;
}
