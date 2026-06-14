#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* input_array(int n);
int count_x(int *arr, int n, int x);
int* filter_x(int *arr, int n, int x, int new_size);
void print_array(int *arr, int size);

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int *arr = input_array(n);

    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    int count = count_x(arr, n, x);
    int new_size = n - count;

    if (new_size == 0) {
        printf("Empty array.\n");
        free(arr);
        return 0;
    }

    int *new_arr = filter_x(arr, n, x, new_size);

    printf("New array:\n");
    print_array(new_arr, new_size);

    free(arr);
    free(new_arr);
    return 0;
}

// Function implementations

int* input_array(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int count_x(int *arr, int n, int x) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            ++count;
        }
    }
    return count;
}

int* filter_x(int *arr, int n, int x, int new_size) {
    int *new_arr = (int*)malloc(new_size * sizeof(int));
    if (new_arr == NULL) {
        printf("Memory allocation error\n");
        free(arr);
        exit(1);
    }
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != x) {
            new_arr[j++] = arr[i];
        }
    }
    return new_arr;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}