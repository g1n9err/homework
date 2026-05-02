#include <stdio.h>   
int main() {         
    int a, b, c;     
    int zaza;        
    printf("Enter a 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) 
    {
        zaza = a;   
        a = b;      
        b = zaza;  
    }
    if (a > c) 
    {
        zaza = a;
        a = c;
        c = zaza;
    }
    if (b > c)
    {
        zaza = b;
        b = c;
        c = zaza;
    }
    printf("Poqric mec: %d %d %d\n", a, b, c);
    return 0;
}