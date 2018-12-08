#include <stdio.h>

int main(){

    float x, y, z, max, min;
    printf("\nEnter 3 number x, y, z: ");
    scanf("%f %f %f", &x, &y, &z);

    max = (x>y)?x:y;
    max = (max>z)?max:z;

    min = (x<y)?x:y;
    min = (min < z)?min:z;

    printf("Max number of %.2f, %.2f and %.2f is: %.2f", x, y, z, max);
    printf("\nMin number of %.2f, %.2f and %.2f is %.2f\n\n", x, y, z, min);
    return 0;
}