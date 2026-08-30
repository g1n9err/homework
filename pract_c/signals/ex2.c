#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int run = 1;

void handle_sigint(int sig) {
    printf("\nShutting down\n");
    run = 0;
}

int main() {

    signal(SIGINT, handle_sigint);
    
    while(run) {
        printf("Start\n");
        sleep(1); 
    }
    

    printf("DONE\n");
    
    return 0;
}
