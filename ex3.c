#include <stdio.h>

int main()
{
	int year;
	int year_now = 2026;

	printf("Enter a year you are born: ");
	scanf("%d", &year);
	printf("You are %d years old\n", year_now - year);
	
	return 0;	
}

