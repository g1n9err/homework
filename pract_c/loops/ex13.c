#include <stdio.h>

int main()
{
    int base;
    int exponent;
    int i = 0;
    int sum = 1;
    scanf("%d %d", &base, &exponent);
    
    while(i < exponent)
    {
        // exp -> 4 
        sum = sum * base;
        i++;
    }
    printf("%d\n",sum);
    return 0;
}