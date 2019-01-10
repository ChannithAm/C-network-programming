/**
 * File              : lab15.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 12.12.2018
 * Last Modified Date: 12.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
int is_prime(int n){
    int i, flag=1;
    if(n<2)
        flag=0;
    else{
        for(i=2; i<=n/2; i++){
            if(n%i==0){
                flag=0;
                break;
            }
        }
    }
    return flag;
}
int main(){
    int i, j, N, cnt=0, A[10];

    do{
        printf("Enter value of N = ");
        scanf("%d", &N);
    }while(0>=N || N>=10);
    printf("\nEnter element of array A:\n");
    for(i=0; i<N; i++){
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }
    printf("\nArray A is : ");
    for(i=0; i<N; i++) printf("%-4d", A[i]);

    for(i=0; i<N; i++){
        if(is_prime(A[i])){
            printf("\ni=%d : %d\t",i, A[i]);
            if(A[i]<2016) cnt++;
        }
    }
    if(cnt>0)printf("\nNumber of prime number in this array : %d\n", cnt);

    return 0;

}
