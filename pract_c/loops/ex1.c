#include<stdio.h>

int main()
{
    printf("for (0-10).\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("%d ", i);
    }
    printf("\n\n");
    printf("while (10-0).\n");
    int j = 10;
    while (j >= 0) 
    {
        printf("%d ", j);
        j--;
    }
    printf("\n\n");
    printf("do/while (0-10).\n");
    int k = 0;
    do 
    {
        printf("%d ", k);
        k++;
    } while (k <= 10);
    printf("\n");

    return 0;
}

