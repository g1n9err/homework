#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *ptr;
    scanf("%d",&n);
    ptr = (int*)calloc(sizeof(int), n);
    printf("Enter the %d array elements:\n", n);
    for(int i = 0; i < n ;i++) {
        scanf("%d", ptr + i);
    }
    int doub_size = n * 2;
    int *new_arr = realloc(ptr,sizeof(int) * doub_size);
    for(int i = n; i < doub_size ; i++) {
        new_arr[i] = 0;
    }
    for (int i = 0; i < doub_size; i++) {
        printf("%d\t", new_arr[i]);
    }
    puts("\n");
    free(new_arr);
    return 0;
} 
