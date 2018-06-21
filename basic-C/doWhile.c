#include <stdio.h>

int main(){
    printf("Do-while loop example.\n");

    int x =1;
    do{
        printf("Value of x = %d,\n", x);
        x = x + 3;
    }while(x < 20);

    return 0;
}