#include <stdio.h>

int main()
{
    int arr[4];
    int div ;
    for(int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 4; i++) {
        arr[i] /= 4;
        div = arr[i];
        printf("%d\t",div );
    }
    return 0;
}
