/**
 * File              : lab11.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 11.12.2018
 * Last Modified Date: 11.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int i,j,N, tmp, sum=0;

    do{
        printf("Enter value of N = ");
        scanf("%d", &N);
    }while(0>=N || N >= 1000);
    printf("===== (0 - %d)", N);
    for(i=1; i<N; i++){
        tmp = 0;
        for(j=1; j<=i/2; j++){
            if(i%j==0) tmp = tmp + j;
        }
        if(tmp==i){printf("|||||%6d", i); sum+=i;}
    }
    if(sum==0) printf("\nNo that number\n");
    else printf("\nSum of that number are: %d\n", sum);

    return 0;
}
