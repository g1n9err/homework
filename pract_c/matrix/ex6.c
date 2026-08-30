#include <stdio.h>
#define SIZE 3

int main() {
    int matr[SIZE][SIZE];
    
    printf("Enter matrix:\n"); 
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            scanf("%d", &matr[i][j]);
        }
    }

    int sum = 0;
    for(int i = 0 ; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i == 1) {
                sum += matr[i][j];
            }
        }
    }
    printf("SUM = %d\n", sum);

    return 0;
}