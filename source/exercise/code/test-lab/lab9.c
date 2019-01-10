/**
 * File              : lab9.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 11.12.2018
 * Last Modified Date: 11.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
#include <math.h>

int main(){
    float epsilon, pi, tmp;
    int n;
    do{
        printf("Enter epsilon (0 - 1): ");
        scanf("%f", &epsilon);
    }while(epsilon <=0 || epsilon >=1);
    pi = 0.0;
    n = 0;
    do{
        tmp = 4.0 / (2*n +1);
        pi = pi + tmp * pow(-1, n);
        n++;
    }while(tmp/4 >= epsilon);
    printf("\nPI = %.4f\n\n", pi);

    return 0;
}
