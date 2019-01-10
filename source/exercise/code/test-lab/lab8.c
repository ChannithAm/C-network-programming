/**
 * File              : lab8.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 11.12.2018
 * Last Modified Date: 11.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>

int main(){
    int i, j, N, A[10];
    int s=0, cnt=0;

    do{
        printf("Enter number of element : ");
        scanf("%d", &N);
    }while(0>= N || N >= 10);
    printf("\nEnter Array A: \n");
    for(i=0; i<N; i++){
        printf("A[%d] : ", i);
        scanf("%d", &A[i]);
    }

    printf("\nArray A is :");
    for(i=0; i<N; i++) printf("%6d", A[i]);

    for(i=0; i<N; i++){
        s = 0;
        for(j=1; j<=A[i]/2; j++){
            if(A[i]%j == 0){
                s += j;
            }
        }
        if(s == A[i] && s>0) {cnt ++; printf("\n%6d", A[i]);}
    }

    printf("\n Number 'hoan thien' in this array are: %d\n", cnt);

}
