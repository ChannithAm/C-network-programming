/**
 * File              : lab6.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 10.12.2018
 * Last Modified Date: 10.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int i, N, A[10], cnt=0;
    float medium = 0;
    do{
        printf("Enter value of N = ");
        scanf("%d", &N);
    }while(0>= N || N >= 10);
    printf("\nEnter array A : \n");
    for(i=0; i<N; i++){
        printf("A[%d] : ", i);
        scanf("%d", &A[i]);
    }
    printf("\nArray A is \n");
    for(i=0; i<N; i++) printf("%d\t", A[i]);

    for(i=0; i<N; i++){
        if(A[i] % 2 == 0){
            cnt++;
            medium = medium + A[i];
        }
    }
    if(cnt == 0)
        printf("\nNo event number!!!\n");
    else
        printf("\nMedium of array A is %.2f\n", medium/cnt);

    return 0;

}
