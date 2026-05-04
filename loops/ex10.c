#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    for(int i = 1; i <= 10; i++)
    {
        printf("%d * %d\t= %d\n", x, i, x * i); // x * i = sum
    }
}