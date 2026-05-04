#include <stdio.h>

int main()
{
    int base;
    int exponent;
    int sum = 0;
    scanf("%d %d", &base, &exponent);
    
    while(sum <= exponent)
    {
        sum = base * exponent;
        sum++;
    }
    printf("%d\n",sum);
    return 0;
}