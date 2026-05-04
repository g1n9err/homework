#include <stdio.h>

void input_array(int arr[],int size){
    for(int x = 0; x < size; x++){
        scanf("%d", &arr[x] );
    }
}

int min_number(int arr[], int size){
    if(size <= 0){
        return 0;
    }
    int min_num = arr[0];
    for(int x = 1; x < size; x++){
       if(min_num > arr[x]) {
            min_num = arr[x];
       }
    }
    return min_num;
}
int main()
{ 
    int arr[10];

    input_array(arr,10);

    int min = min_number(arr,10);
    printf("%d\n", min);
    return 0;
}
