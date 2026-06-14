#include <stdio.h>
#include <stdlib.h>

int main () {
    int n; 
    scanf("%d", &n);
    int *ptr;
    ptr = (int*)malloc(sizeof(int) * n);
    for( int i = 0; i < n; i++) {
        scanf("%d", ptr + i);    
    } 
    int k;
    printf("please enter a k which is smaller than n: ");
    scanf("%d", &k);

    if(k > n) {return 1;}
    int *new_arr = realloc(ptr, sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        printf("%d\t", new_arr[i]);
    } 
    free(ptr);
    return 0; 
} 