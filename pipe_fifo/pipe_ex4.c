
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define SIZE 1024

typedef struct {
    int letters;
    int digits;
    int spaces;
    int lines;
} TextStats;

int main () {
    int p2c[2];
    int c2p[2];

    if(pipe(p2c) == -1) {
        perror("pipe");
        return 1;
    }
    
    if(pipe(c2p) == -1) {
        perror("pipe");
        return 1;
    }
    
    pid_t pid;
    pid = fork();
    if(pid < 0){
        perror("fork");
        return 1;
    }
    TextStats stats = {0,0,0,0};

    if(pid > 0){
        close(p2c[0]);
        close(c2p[1]);
        const char *pr_buf = "CHLP mlp 2.4 cpp\nchlpmlp\n12 34";
        write(p2c[1],pr_buf,strlen(pr_buf) + 1);
        close(p2c[1]);
        wait(NULL);
        read(c2p[0], &stats, sizeof(stats));
        printf("letters = %d\n",stats.letters);
        printf("digits = %d\n", stats.digits);
        printf("spaces = %d\n", stats.spaces);
        printf("lines = %d\n",stats.lines);

    }else if(pid == 0) { 
        close(p2c[1]);
        close(c2p[0]); 
        char ch_buffer[SIZE];
        ssize_t bytes_read;
        while((bytes_read = read(p2c[0],ch_buffer,sizeof(ch_buffer))) != 0) {
            if(bytes_read == -1) {
                if(errno == EINTR) {
                    continue;
                }
                perror("read");
                break;
            } 

        for(int i = 0; i <  bytes_read; ++i){
            char simb = ch_buffer[i];
            if(simb >= '0' && simb <= '9'){
                stats.digits ++;
            } else if(simb == ' ') {
                stats.spaces ++;
            } else if(simb >= 'a' && simb <= 'z' ||  simb >= 'A' && simb <= 'Z'){
                stats.letters ++;
            } else if(simb == '\n'){
                stats.lines ++;
            }
        }
    }
        close(p2c[0]);
        write(c2p[1], &stats,sizeof(stats));
        close(c2p[1]);
    }
    return 0;
}
