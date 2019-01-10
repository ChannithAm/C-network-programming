/**
 * File              : lab22.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 13.12.2018
 * Last Modified Date: 13.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include<stdio.h>
#include<math.h>

int fact(int x){
    if(x>1){
        return x * fact(x-1);
    }
    else {
        return 1 ;
    }
}

int main () {
    int i=1 , sign=1;
    float x, result, tmp;
    printf("Enter x = ");
    scanf("%f",&x);
    result = 0;
   do{ 
        //result = result + sign*(pow(x,i)/fact(i));
        tmp = pow(x, i)/fact(i);
        result += sign*tmp;
        i+=2;
        sign *= -1 ;
    }while(tmp>=0.0001);
    printf("result= %f\n",result);
    return 0 ;
}
