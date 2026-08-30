#include "header.h"

int arr_input (int *arr, int n){
    printf("Enter the %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    return 0;
}

int sum(int *arr, int n) {
    int su = 0;
    for(int i = 0; i < n; i++ ) {
        su += arr[i];
    }
   return su;
    
}

float average(int *arr, int n) {
    float avg;
    avg = (float)sum(arr,n) / n;
    return avg;
}

int max_output(int *arr, int size){
    int max_num = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max_num) {
            max_num = arr[i];
        }
    }
    return max_num;
}

int min_output(int *arr, int size){
    int min_num = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min_num) {
            min_num = arr[i];

        }
    }
    return min_num;
}

void reverse(int *arr, int size) {
    int j = size - 1;
    while(j >= 0) {
        printf("%d\t",arr[j]);
        j--;
    }
}

int* arr_fill(int *arr,int size) {
    int *new_arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }
    return new_arr;
}