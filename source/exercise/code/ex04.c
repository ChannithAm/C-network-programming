#include <stdio.h>
#include <math.h>

int main(){
    float x, y, z, F=0;

    printf("Enter value of x, y, z: ");
    scanf("%f %f %f", &x, &y, &z);
    
    F =  (x+y+z)/(pow(x, 2) + pow(y, 2) + 1) - fabs(x-z*cos(y));

    printf("Value of F = %6.4f\n", F);
}


