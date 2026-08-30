#include "matrix.h"

int** matrix(int x, int y){
    int **matr = (int **)malloc(x * sizeof(int*));
    if(matr == NULL) { exit(1); }
    for(int i = 0; i < x; ++i) {
        matr[i] = (int*)malloc(y * sizeof(int));
        if(matr[i] == NULL) {
            free(matr);
            exit(1);
        }
    }
    return matr;
}

void input_matrix(int **arr, int x, int y) {
    for(int i = 0; i < x; ++i){
        for(int j = 0; j < y; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
}

void output_matrix(int **arr,int x, int y) {
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j){
            printf("%d\t", arr[i][j]);
        }   
        printf("\n");
    }
    //printf("\n");
}

long mull_matrix(int** arr, int x, int y){
    long mull = 1;
    for (int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j ) {
            mull *= arr[i][j];
        }
    }
    return mull;
}

int sum_matrix(int **arr, int x, int y) {
    int sum = 0;
    for (int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j ) {
            sum += arr[i][j];
        }
    }
    return sum;
}

void free_matrix(int **arr, int x){
    for(int i = 0; i < x; ++i) {
        free(arr[i]);
    }
    free(arr);
}

