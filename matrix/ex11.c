#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows;
    int cols;

    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("Enter cols: ");
    scanf("%d", &cols);

    int **matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) { exit(1); }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            for (int k = 0; k < i; ++k) {
                free(matrix[k]);
            }
            free(matrix);
            exit(1);
        }
    }

    printf("Enter matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]); 
        }
    }

    int *col_sum = (int*)malloc(cols * sizeof(int));
    if (col_sum == NULL) { exit(1); }

    
    for (int i = 0; i < cols; ++i) {
        int current_sum_col = 0;
        for (int j = 0; j < rows; ++j) {
            current_sum_col += matrix[j][i];
        }
        col_sum[i] = current_sum_col; 
    }
    printf("\nCol sums:\n");
    for (int i = 0; i < cols; ++i) {
        printf("col_sum[%d] = %d\n", i, col_sum[i]);
    }

    for (int i = 0; i < rows; ++i) {
        free(matrix[i]); 
    }
    free(matrix);    
    free(col_sum);   

    return 0;
}
