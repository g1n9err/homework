#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    if (N < 0)
        N *= -1;
    int sum = 0;

    for(int x = 1; x <= N; x++)
    {
        sum += x;
    }
    printf("%d\n", sum);
    return 0;
}