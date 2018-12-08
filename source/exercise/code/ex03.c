#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a,b, max;
    
    printf("\n a="); scanf("%f", &a);
    printf("\n b="); scanf("%f", &b);

    max = a;

    if(max < b)
        max = b;

    printf("Maximum number of (%6.2f, %6.2f) is %6.2f\n", a, b, max);
    return 0;
}
