#include <stdio.h> 
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(sizeof(int));
    int index = 0;
    int value;

    while(1) {
        scanf ("%d", &value);
        if(value == 0) {
            printf("Exit\n");
            break;
        } 
        arr = (int*)realloc(arr, (index + 1) * sizeof(int));
        arr[index] = value;
        index++;
    }

    for (int i = 0; i < index; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");
    free(arr);
    return 0;
}