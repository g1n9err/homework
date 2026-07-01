#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int matr[n][n];

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matr[i][j]);
        }
    }

    int dia_sum = 0;
    int secD_sum = 0;


for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j) {
            dia_sum += matr[i][j];
        }
        
        if (i + j == n - 1) {
            secD_sum += matr[i][j];
        }
        
    }
}

    
    printf("\nMain diagonal sum: %d\n", dia_sum);
    printf("Sec diagonal sum: %d\n", secD_sum);

    return 0;
}