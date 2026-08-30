#include <stdio.h>

int main()
{
    int arr[5];
    int zaza;
    int count = 0;
    for(int x = 0; x < 5; x++) {
        scanf("%d", &arr[x]);
    }
    for(int x = 0; x < 5; x++) {
        if(arr[x] % 2 != 0) {
            zaza = arr[x];
            count ++;
        }
    }
    printf("Odd number count: %d\n", count);
    return 0;
}

 