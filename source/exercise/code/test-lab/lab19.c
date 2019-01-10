/**
 * File              : lab19.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int a,d, b, i=0, con[8];
    printf("Base 10 to base 2 converter\n");
    printf("Enter a = ");
    scanf("%d", &a);
    d = a;
    while(a!=0){
        b=a%2;
        a=a/2;
        con[i]=b;
        i++;
        //printf("%2d", b);
    }
    printf("\n%d in base 10 is equal to ",d);
    for(i=i-1; i>=0; i--)
        printf("%d", con[i]);
    printf(" in base 2\n");

    return 0;
}
