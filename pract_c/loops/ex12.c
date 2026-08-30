#include <stdio.h>

int main()
{
    int a, b;
    int mul = 0;
    int x = 0;
    scanf("%d %d", &a, &b);
    
    while(x < b)
    {
        mul += a;
        x++;
    }

    printf("%d\n", mul);
    return 0;
}
