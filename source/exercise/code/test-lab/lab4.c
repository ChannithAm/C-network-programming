/**
 * File              : lab4.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 10.12.2018
 * Last Modified Date: 10.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,N;
    int cnt = 0;
    float A[10], sum=0;
    //float cnt = 0;

    do{
        printf("Enter value of N = ");
        scanf("%d", &N);
    }while(0>=N || N >= 10);
    
    printf("\nEnter element of array N");
    printf("\n------------------------\n");
    for(i=0; i<N; i++){
        printf("A[%d] : ", i);
        scanf("%f", &A[i]);
    }
    printf("\nArray A is : ");
    for(i=0; i<N; i++) printf("%.2f\t", A[i]);
    
    for(i=0; i<N; i = i+2){
        if(A[i] < A[i+1]){
            cnt ++;
            sum = sum + A[i+1];
        }
    }
    if(cnt == 0){
        printf("\nMax element dosen't exits!!!\n");
    }
    else{
        printf("\nSum of max elements: %.2f\n", sum);
    }

    return 0;
}
