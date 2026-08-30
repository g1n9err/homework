#include <stdio.h>

int main()
{
    int secret = 17;
    int guess;
    
    while (1)
    {
        scanf("%d", &guess);
        if(guess == secret)
        {
            printf("you are correct!\n");
            break;
        } else if (guess > secret) {
            printf("Aveli poqr\n");
        }
        else
        {
            printf("Aveli mec\n");
        }
    }
    
    return 0;
}