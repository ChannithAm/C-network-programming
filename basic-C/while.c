#include <stdio.h>

int main(){
    printf("While loop example\n");

    int x = 2;
    while(x<10)
    {
        printf("Value of x = %d \n",x);

        x = x + 3;

    }
    return 0;

}