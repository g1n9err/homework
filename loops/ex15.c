#include <stdio.h>

int main()
{
    char ch;
    scanf("%c",&ch);

    switch(ch)
    {
        case 'a':
        case 'u':
        case 'i':
        case 'o':
        case 'e':
            printf("dzaynavor e\n");
            break;
        default: 
            printf("baxadzayn e\n");
            break;
    }

    return 0;

}