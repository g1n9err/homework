#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE 4

typedef struct  {
    int sum;
    int average;
    int max;
    int min;
} ArrayStats;

int main() {
    int fds1[2];
    int fds2[2];

    if (pipe(fds1) == -1 || pipe(fds2) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        close(fds1[0]);
        close(fds2[1]);

        int arr[4] = {10, 20, 30, 40};
        write(fds1[1], arr, sizeof(arr));
        close(fds1[1]);

        ArrayStats stats;
        read(fds2[0], &stats, sizeof(ArrayStats));
 
        wait(NULL);

        printf("Sum: %d\n", stats.sum);
        printf("Average: %d\n", stats.average);
        printf("Maximum: %d\n", stats.max);
        printf("Minimum: %d\n", stats.min);
    } else if(pid == 0) {
        close(fds1[1]);
        close(fds2[0]);

        int received_arr[SIZE];
        read(fds1[0], received_arr, sizeof(received_arr));
        close(fds1[0]);

        ArrayStats stats;
        stats.sum = 0;
        stats.max = received_arr[0];
        stats.min = received_arr[0];

        for (int i = 0; i < SIZE; i++) {
            stats.sum += received_arr[i];
            if (received_arr[i] > stats.max) {
                stats.max = received_arr[i];
            }
            if (received_arr[i] < stats.min) {
                stats.min = received_arr[i];
            }
        }
        stats.average = stats.sum / SIZE;

        write(fds2[1], &stats, sizeof(ArrayStats));
        close(fds2[1]);

        exit(0);
    }

    return 0;
}
