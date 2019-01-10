/**
 * File              : lab5.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 10.12.2018
 * Last Modified Date: 10.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */

#include <stdio.h>
#include <math.h>

int is_prime(int n){
    int i, j;
    if(n < 2) return 0;
    else{
        for(i=2; i<=n/2; i++){
            if(n%i == 0)
                return 0;
        }
    }
    return 1;
}

int main(){
    int i, N, cnt=0;
    int A[10];
    int B[10];

    do{
        printf("=======================\n");
        printf("Enter value of N = ");
        scanf("%d", &N);
    }while(0>=N || N >= 10);
    printf("\nEnter array of A:  \n");
    for(i=0; i<N; i++){
        printf("A[%d] : ", i);
        scanf("%d", &A[i]);
    }
    printf("\nArray A is : ");
    for(i=0; i<N; i++) printf("%d\t", A[i]);
    printf("\n");
    for(i=0; i<N; i++){
        if(is_prime(A[i])){
            B[cnt] = A[i];
            cnt ++;
            printf("%d\t", A[i]);
        }
    }
    if(cnt != 0) printf("\nThere are %d prime numbers\n\n", cnt);
    for(i=0; i<cnt; i++) printf("\nArray B is %d", B[i]);

    return 0;
}
