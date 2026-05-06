#include <stdio.h>

int main()
{
    int arr[5];
    int zaza;
    for(int x = 0; x < 5; x++) {
        scanf("%d", &arr[x]);
    }
    for(int x = 0; x < 5; x++) {
        if(arr[x] % 2 != 0) {
            zaza = arr[x];
             printf("%d\t",zaza);
        }
    }
    return 0;
}

 