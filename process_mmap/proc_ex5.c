#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main () {

    pid_t pid = fork();
    int status;

    if(pid < 0){
        perror("fork");
        return 1;
    }
    
    if(pid == 0) {
        printf("child pid: %d\n",getpid());
        sleep(10);

        printf("Child end normally");
        exit(33);

    } else {
        sleep(2);
        printf("Parent send signal\n");
        kill(pid, SIGINT);
        wait(&status);
    }

    if(WIFEXITED(status)) {
        printf("chlid ends normally, whit status: %d\n",WEXITSTATUS(status));
    } else if(WIFSIGNALED(status)) {
        printf("Child end whit signal: %d\n", WTERMSIG(status));
    }
    return 0;
}