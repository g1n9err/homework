#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows;
    int cols;
    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("Enter cols: ");
    scanf("%d", &cols);

    int **matrix = (int**)malloc(rows * sizeof(int*));
    if(matrix == NULL) {exit(1);}
    for(int i = 0; i < rows; ++i){
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if(matrix[i] == NULL){
            free(matrix);
            exit (1);
        }
    }
    
    printf("Enter matrix:\n ");
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int *row_sum = (int*)malloc(rows * sizeof(int));
    if (row_sum == NULL) { exit(1); }

    for (int i = 0; i < rows; ++i) {
        int current_sum = 0;
        for (int j = 0; j < cols; ++j) {
            current_sum += matrix[i][j];
        }
        row_sum[i] = current_sum; 
    }

    
    printf("\nRow sums:\n");
    for (int i = 0; i < rows; ++i) {
        printf("row_sum[%d] = %d\n", i, row_sum[i]);
    }


    for (int i = 0; i < rows; ++i) {
        free(matrix[i]); 
    }
    free(matrix);    
    free(row_sum);

    return 0;
}


