/**
 * File              : lab10.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 11.12.2018
 * Last Modified Date: 11.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    float a, b, c, x1, x2, delta;
    printf("Enter value of a b c respectly: ");
    scanf("%f %f %f", &a, &b, &c);

    if(a==0){
        if(b==0 && c==0) printf("Equation has inf root");
        else if(b==0 && c!=0) printf("Equation has no root");
        printf("Equation has only one root: %.2f\n", -c/b);
    }
    else{
        delta = b*b - 4*a*c;
        if(delta == 0){
            printf("Equation has root x1=x2= %.2f \n", -b/(2*a));
        }
        else{
            if(delta > 0){
                printf("Equation has 2 roots x1=%.2f, x2=%.2f\n",
                        (-b + sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
            }
            else{
                printf("Equation has 2 complex roots x1= %.2f+%.2fj,x2= %.2f -%.2fj\n", -b/(2*a), sqrt(abs(delta))/(2*a), -b/(2*a), sqrt(abs(delta))/(2*a));
            }
        }
    }
    return 0;
}
