/* օգտվողին թույլ կտա մուտքագրել մի ամբողջ թիվ։
 Եթե աժանվում է 3-ի և 5-ի, տպել «FizzBuzz», եթե միայն 3-ի՝ «Fizz», միայն 5-ի՝ «Buzz», ոչ մեկի՝ ոչինչ։*/
#include<stdio.h>
int main()
{
    int s;
    scanf("%d",&s);
    if(s % 3 == 0 && s % 5 == 0)
    {
        printf("FizzBuzz");
    }
    else 
    {
        if(s % 3 == 0)
        {
            printf("Fizz");
        }
        else 
        {
            if(s % 5 == 0 )
            {
                printf("Buzz");
            }
        }
    }
return 0;
}