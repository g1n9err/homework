#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int m;
    
    printf("enter n:  ");
    scanf("%d", &n);
    printf("enter m: ");
    scanf("%d", &m);
    
    
    int **matr = (int**)malloc (n * sizeof(int*));
    if (matr == NULL) {exit (1);}

    for (int i = 0; i < n; ++i) {
    matr[i] = (int*)malloc(m * sizeof(int) );
        if(matr[i] == NULL) {
            free(matr[i]);
            exit (1);
        }
    }

    printf("array init :\n" );
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &matr[i][j]);
        }
    }
    
    printf("\nmatrix: \n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d\t", matr[i][j]); 
       }
        printf("\n"); 
    }
    
    for(int i = 0; i < n; ++i) {
        free(matr[i]);
    }

    free(matr);
    
    return 0;
}
