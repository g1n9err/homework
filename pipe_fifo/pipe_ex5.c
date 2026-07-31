#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>


typedef struct 
{
    float celsius;
}Temperature;

typedef struct 
{
    float fahrenheit;
}ConvertedTemperature;

int main() {
    int p2c[2];
    int c2p[2];
    
    if(pipe(p2c) == -1){
        perror("pipe");
        return 1;
    }
    if(pipe(c2p) == -1){
        perror("pipe");
        return 1;
    }
    
    Temperature temp;
    printf("Write the temperature in Celsius։ ");
    scanf("%f", &temp.celsius);
    printf("\n");
    ConvertedTemperature conv_temp;
    
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return 1;
    }

    if(pid > 0) {
        close(p2c[0]);
        close(c2p[1]);
        
        write(p2c[1],&temp,sizeof(Temperature));
        
        //puts("greci");
        
        close(p2c[1]);
        //puts("z");
        wait(NULL);
        //puts("zz");
        read(c2p[0],&conv_temp,sizeof(ConvertedTemperature));
        //puts("zzz");
        close(c2p[0]);
        
        //puts("kardaci");
        
        printf("Temperature in Fahrenheit: %.2f\n", conv_temp.fahrenheit);
    } else if (pid == 0) {
        printf("mtela ste\n");
        close(c2p[0]);
        close(p2c[1]);
        //puts("g");    
        read(p2c[0],&temp,sizeof(Temperature));
        //puts("erexen kardac");
        
        
        conv_temp.fahrenheit = (temp.celsius * 1.8) + 32;
        close(p2c[0]);
        
        write(c2p[1],&conv_temp,sizeof(ConvertedTemperature));
        //puts("gg");
        close(c2p[1]);
        
        puts("erexen grec");
    }
    
    return 0;
}
