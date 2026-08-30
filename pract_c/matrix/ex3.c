#include <stdio.h>

#define SIZE 4 

int main() {
    int matr[SIZE][SIZE];

    printf("Enter elements for a 4x4 matrix:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &matr[i][j]);
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matr[i][j] = matr[i][j] * matr[i][j]; 
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d\t", matr[i][j]);
        }
        printf("\n");
    }

    return 0;
}