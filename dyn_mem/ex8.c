#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int m;
    int *ptr_n;
    int *ptr_m;
    
    printf("n: ");
    scanf("%d", &n);
    printf("m: ");
    scanf("%d", &m);
    ptr_n = (int*)malloc(sizeof(int) * n);
    ptr_m = (int*)malloc(sizeof(int) * m);

    printf("ptr_n: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d",ptr_n + i);
    }
    printf("ptr_m: \n");
    for(int i = 0; i < m; i++) {
        scanf("%d", ptr_m + i);
    }
    int *new_arr;
    new_arr = (int*)malloc(sizeof(int) * (n + m));
    for(int i = 0; i < n; i++) {
        new_arr[i] = ptr_n[i];
    }
    int tmp = 0;
    for(int i = n; i < (n + m); i++) {
        new_arr[i] = ptr_m[tmp];
        tmp++;
    }
    
    for(int i = 0; i < (n + m); i++) {
        printf("%d\t", new_arr[i]);
    }
    puts("\n");

    free(new_arr);
    free(ptr_n);
    free(ptr_m);

    return 0;
}  
