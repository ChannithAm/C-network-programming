// Program to add two distaces which is in feet and inches

#include <stdio.h>

struct Distance{
    int feet;
    float inch;
}dist1, dist2, sum;

int main(){
    printf("1st distatce\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);
    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    printf("\n\n2nd distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);
    printf("Enter inch: ");
    scanf("%f", &dist2.inch);

    // adding feet
    sum.feet = dist1.feet + dist2.feet;
    // adding inch
    sum.inch = dist1.inch + dist2.inch;

    // Changing feet if inch is greater than 12.
    while(sum.inch >=12){
        ++sum.feet;
        sum.inch = sum.inch - 12;
    }

    printf("\nDistance 1: %d feet, %4.2f inch", dist1.feet, dist1.inch);
    printf("\nDistance 2: %d feet, %4.2f inch", dist2.feet, dist2.inch);
    printf("\nSum of distance = %d\'-%.1f\"\n", sum.feet, sum.inch);
}