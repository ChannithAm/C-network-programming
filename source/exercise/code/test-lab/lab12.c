/**
 * File              : lab12.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int i, j, cnt, N, prime, sum=0;
    do{
        printf("Enter value of N : ");
        scanf("%d", &N);
    }while(0 >=N || N >=200);

    for(i=2; i<N; i++){
        cnt=0;
        for(j=2; j<=i/2; j++){
            if(i%j==0){cnt++; break;}
        }
        if(cnt==0){
            printf("%-4d", i);
            sum += i;
        }
    }
    if(sum==0) printf("\nNo prime number!");
    else
        printf("\nSum of prime number is %d", sum);
    printf("\n\n");
}
