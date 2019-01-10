/**
 * File              : lab16.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
int main(){
    int M,N,i,s,d=0;
    do{
        printf("|Enter 1<N<2000: ");
        scanf("%d", &N);
    }while(N<=1 || N>=2000);
    do{
        printf("|Enter 1<M<2000: ");
        scanf("%d", &M);
    }while(M<=1 || M>=2000);

    s=0;
    for(i=1; i<=N/2; i++){
        if(N%i==0) s = s + i;
    }
    if(s==M){
        d++;
        s = 0;
        for(i=1; i<=M/2; i++){
            if(M%i==0) s = s+i;
        }
        if(s==N) d++;
    }
    if(d==2) printf("The two number are friendly number.\n");
}
