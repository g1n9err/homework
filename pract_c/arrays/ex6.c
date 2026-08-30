#include <stdio.h>

int main()
{
    int arr[4];
    int sum = 0;
    int mul =  1;
    for(int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    } 
    for(int i = 0;i < 4; i++) {
        sum += arr[i];
        mul *= arr[i];
    }
    
    printf("gumar: %d\n", sum);
    printf("artadryal: %d\n", mul);
    return 0;
}
