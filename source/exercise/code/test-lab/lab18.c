/**
 * File              : lab18.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include<stdio.h>
int main(){
    int N,n,T,i;
    do{
        printf("Enter 0<N<10000: ");
        scanf("%d", &N);
    }while(N<=0 || N>=10000);
    printf("That number are: ");
    for(i=1; i<N; i++){
        T=0; n=i;
        while(n!=0){
            T = T+ (n%10)*(n%10)*(n%10);
            n = n/10;
        }
        if(T==i) printf("%6d", i);
    }
    printf("\n");
    return 0;
}
