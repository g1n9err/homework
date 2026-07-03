#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig) {
    printf("\nEs chem pakvelu\n");
}

int main() {
    signal(SIGINT, handle_sigint);

    printf("Enter ctrl+C\n");

    while(1) {
        printf("chlp\n");
        sleep(1); 
    }

    return 0;
}
