#include <stdio.h>

int main()
{
    int x;
    int sum = 1;
    scanf("%d", &x);
    
    while(x > 0)
    {
        sum *= x;
        x--;
    }
    printf("%d\n", sum);
    return 0;
}
