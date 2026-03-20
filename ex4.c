#include <stdio.h>

int main()
{
	int a;
	int b;

	printf("Enter a width(a): ");
	scanf("%d", &a);
	printf("Enter a length(b): ");
	scanf("%d", &b);
	printf("The perimetor is: %d\n", 2*a+2*b );

	return 0;

}

