#include<stdio.h>
int main()
{
   int x = 1;

   while(x<=100)
   {
       if(x % 2 != 0)
       {
           printf("%i\n", x);
       }
       x++;
   }
   return 0;
}
