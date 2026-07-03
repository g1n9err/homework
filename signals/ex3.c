#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main (){
    
    sigset_t list;
    sigemptyset(&list);
    sigaddset(&list , SIGINT);
    
    sigprocmask(SIG_BLOCK, &my_set, NULL);

    for(int i = 0; i <= 10; ++i) {
        printf("CHLP");
        sleep(10);
    }

}
