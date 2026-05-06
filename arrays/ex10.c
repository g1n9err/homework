#include <stdio.h>

int main() {
    int arr[4];
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < 4; i++) {
        sum += arr[i];
        
    }
    printf("%d\n", sum / 4);
    
    return 0;
}
