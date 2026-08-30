#include <stdio.h>

int main()
{
    int num;
    int sum = 0;

    while(1)
    {
        scanf("%d", &num);
        
        if(num > 0)
            sum += num;

        else if (num == 0)
        {
            printf("%d\n", sum);
            break;
        }
        
    }
    return 0;
}