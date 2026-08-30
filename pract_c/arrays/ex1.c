#include <stdio.h>

void input_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int max_number(int arr[], int size) {
    if (size <= 0)
        return 0;

    int max_number = arr[0];

    for (int i = 1; i < size; i++) {
        if (max_number < arr[i]) {
            max_number = arr[i];
        }
    }

    return max_number;
}

int main()
{
    int arr[5];

    input_array(arr, 5);
    int max = max_number(arr, 5);

    printf("%d\n", max);
    return 0;
}
