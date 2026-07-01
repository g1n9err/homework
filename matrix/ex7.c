#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter n; ");
    scanf("%d", &n);

    int **arr = (int**)malloc(n * sizeof(int*));
    if (arr == NULL) {exit (1);}

    for(int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc(n * sizeof(int));
        if(arr[i] == NULL) {
            free(arr[i]);
            exit (1);
        }
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix:\n ");
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j >= 0; --j) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; ++i) {
        free(arr[i]);
    }

    free(arr);
    return 0;
}