/**
 * File              : lab21.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 13.12.2018
 * Last Modified Date: 13.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int i, N, cnt=0, sum=0, A[10];
    do{
        printf("Enter 0<N<10: ");
        scanf("%d", &N);
    }while(0>=N || N>=10);
    printf("Enter element of Array A: \n");
    for(i=0; i<N; i++){
        printf("A[%d] : ", i);
        scanf("%d", &A[i]);
    }
    printf("\nArray A is ");
    for(i=0; i<N; i++) printf("%d\t", A[i]);

    for(i=0; i<N; i++){
        if(A[i-1] + A[i+1] == A[i]){
            cnt++;
            sum = sum + A[i];
        }
    }
    if(cnt==0) printf("\nNo that element\n");
    else
        printf("\nSum of that number is %d\n", sum);

    return 0;

}
