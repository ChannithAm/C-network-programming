/**
 * File              : lab7.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 10.12.2018
 * Last Modified Date: 11.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int i, j, N,max1, max2, A[10], tmp;

    do{
        printf("|Enter N = ");
        scanf("%d", &N);
    }while(0>=N || N >= 10);
    printf("\nEnter element of array A : \n");
    for(i=0; i<N; i++){
        printf("A[%d] : ", i);
        scanf("%d", &A[i]);
    }
    printf("\n=============================\n");
    printf("Array A is \n");
    for(i=0; i<N; i++){
        printf("%6d", A[i]);
    }

    if(N < 2) printf("\nNo the second number that is maxx");
    else{
        max1 = A[0];
        for(i=0; i<N; i++){
            if(max1 < A[i]){
                max1 = A[i];
            }
        }

        max2 = A[0];
        for(i=0; i<N; i++){
            if(max2 < A[i] && A[i] < max1){
                max2 = A[i];
            }
        }
        printf("\nThe second largest number is %d\n", max2);
    }
    return 0;
}
