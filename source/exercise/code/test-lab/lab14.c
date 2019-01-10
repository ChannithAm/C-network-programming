/**
 * File              : lab14.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
int main(){
    int i,j, N, A[10], cnt=0, s;

    do{
        printf("Enter value of N = ");
        scanf("%d", &N);
    }while(0>=N || N>=10);
    printf("\nEnter element of array A :\n");
    for(i=0; i<N; i++){
        printf("A[%d] : ",i);
        scanf("%d", &A[i]);
    }
    printf("\nArray A is : ");
    for(i=0; i<N; i++) printf("%-4d", A[i]);
    printf("\nThat number in place : ");
    for(i=0; i<N; i++){
        s = 0;
        for(j=1; j<=A[i]/2; j++){
            if(A[i]%j==0) s = s + j;
        }
        if(s == A[i]&& s>0){
            printf("%d", i);
            if(A[i] < 2016) cnt++;
        }

    }
    printf("\nNumber of that number are %d\n", cnt);
    
    return 0;
}
