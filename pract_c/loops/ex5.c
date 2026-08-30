#include<stdio.h>
int main()
{
    int x = 1;

    while(x<=100)
    {
        if(x != 3 && x != 5 && x != 15)
         {
            printf("%i\n",x);
         }

        x++;
    }
    return 0;
}
