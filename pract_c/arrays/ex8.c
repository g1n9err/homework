#include<stdio.h>

int main() {
    int arr[4];
    int arr1[4];
    int sub ;

    for(int i = 0 ; i < 4; i++) {
        scanf("%d %d", &arr[i], &arr1[i]);
    }
    for(int i = 0; i < 4; i++) {
        sub = arr[i] * arr1[i];
        printf("%d\n", sub);
    }
    return 0;
}
