#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if(pid < 0){
        perror("fork");
        return 1;
    }
    
    if(pid == 0) {
        printf("child sleep");
       
        sleep(3);
    } else {
        printf("Waiting .. ");
        wait(NULL);
    }
    printf("\n");
    return 0;
}
