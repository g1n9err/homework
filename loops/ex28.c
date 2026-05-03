#include<stdio.h>
int main()
{
int n=0;
scanf("%d",&n);
for(int i=0; i<n-1; i++)
{
    for(int j=0; j<2*n; ++j)
    {
        if(((n+i)==j) || ((n-i)==j))
        {
            printf("*");
        }
            else 
            {
                printf(" ");
            }
    }
     printf("\n");
}
for (int i=0; i<n;++i)
{
    printf("* ");
}
}

