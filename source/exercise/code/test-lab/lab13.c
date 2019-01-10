/**
 * File              : lab13.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
int main(){
    int i, N, X, A[10];
    int cnt=0;
    do{
        printf("|Enter value of N = ");
        scanf("%d", &N);
    }while(0>=N || N>=10);
    printf("\nEnter element of Array A\n");
    for(i=0; i<N; i++){
        printf("A[%d]", i);
        scanf("%d", &A[i]);
    }
    printf("\nArray A is : ");
    for(i=0; i<N; i++) printf("%-4d", A[i]);
    do{
        printf("\nEnter any value of X from keyboard: ");
        scanf("%d", &X);
    }while(X>=10);
    for(i=0; i<N; i++){
        if(X==A[i]) cnt++;
    }
    printf("\nNumber of element in array equal to %d are %d\n", X, cnt);

    return 0;
}
