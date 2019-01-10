/**
 * File              : lab20.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int M,N,i, d=0, T=0;
    do{
        printf("\nEnter M, N: ");
        printf("\nN = ");scanf("%d", &N);
        printf("\nM = ");scanf("%d", &M);
    }while(N<=0 || M<=0);
    for(i=1; i<=N; i++){
        if(M%i==0 && N%i==0)
        {d++; T+=i;}
    }
    printf("\nTwo number has %d uoc so chung, sum = %d\n", d,  T);
    return 0;
}
