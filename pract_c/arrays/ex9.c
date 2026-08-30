#include <stdio.h>

int main()
{
    int arr[4];
    for(int x = 0; x < 4; x++) {
        scanf("%d", &arr[x]);
    }
    for(int x = 4 - 1; x >= 0; x--) {
        printf( "%d\t",arr[x]);
    }
    return 0;
}
