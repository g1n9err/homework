#include<stdio.h>
int main ()
{
    int a,b;
    int count = 0;

    scanf("%d %d", &a, &b);
    
    if(a>b)
    {
        int zaza = a;
        a = b;
        b = a;
    }

    for (int x = a; x <= b; x++)
    {
        if (x % 5 == 0)
        {
            count++;
        }
    }
    
    printf ("%d", count);
}
