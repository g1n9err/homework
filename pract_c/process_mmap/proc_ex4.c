#include <stdio.h>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/wait.h>
#include <stdlib.h>

void cleanup1() {
    printf("cleanup 1\n");
}

void cleanup2(){
    printf("cleanuo 2\n");
}

int main() {
    atexit(cleanup1);
    atexit(cleanup2);
    
    printf("es arden prcel em\n");

    return 0;
}
