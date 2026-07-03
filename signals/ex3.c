#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main (){
    
    sigset_t list;
    sigemptyset(&list);
    sigaddset(&list , SIGINT);
    
    sigprocmask(SIG_BLOCK, &list, NULL);

    for(int i = 0; i <= 10; ++i) {
        printf("CHLP\n");
        sleep(1);
    }
    printf("\nDONE\n");

    sigprocmask(SIG_UNBLOCK, &list , NULL);
    
    printf("\nStop process\n");

    return 0;
}

