#include <stdio.h>

int main()
{
    int N;
    int sum = 0;
    scanf("%d", &N);

    if(N < 0)
    {
        N *= -1;
    }

    for(int x = 1; x <= N; x++)
    {
        if(x % 2 != 0)
        {
            sum += x;
        }
    }
    printf("%d\n", sum);
    return 0;

}