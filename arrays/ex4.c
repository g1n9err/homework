#include <stdio.h>

void input_volue(int arr[], int size) {
    for(int x = 0; x < size; x++) {
        scanf("%d", &arr[x]);
    }
}

int max_index(int arr[],int size) {
    if(size <= 0)
    return 0;

    int index = 0;

    for(int x = 1; x < size; x++) {
        if(arr[index] > arr[x]) {
            index = x;
        }
    } 
    return index;
}

int main() {

    int arr[4];

    input_volue(arr, 4);
    int index = min_index(arr,4);
    printf("%d", index);
    return 0;
}