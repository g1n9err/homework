#include  "header.h"

int main() {
    int n;
    int *arr;
    
    printf("Enter n: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    arr_input(arr,n);
    //int res = sum(arr,n);
    //float res = average(arr,n);
    //int res_max = max_output(arr,n);
    //int res_min = min_output(arr,n);
    //printf("%d %d\n", res_max, res_min);
    //reverse(arr,n);
    int *res = arr_fill(arr,n);
    for (int i = 0; i < n; i++) {
        printf("%d\t", res[i]);
    }
    
    printf("\n");
    free(arr);
    free(res);
    return 0;

}


