#include <stdio.h>

int main(){
    int i, N, x, A[10];
    int sum=0;
    float m=0;

    do{
        printf("Enter value of N = ");
        scanf("%d", &N);
    }while(N<=0 || N>=10);

    printf("\nEnter element of array A[%d]\n", N);
    for(i=0; i<N; i++){
        printf("A[%d]: ", i+1);
        scanf("%d", &A[i]);
    }
    printf("Array of A is : ");
    for(i=0; i<N; i++) printf("%d\t", A[i]);

    do{
        printf("\nEnter value of x = ");
        scanf("%d", &x);
    }while(x <= 0);
    if(x <= N){
        for(i=0; i<N; i++)
            m = m + A[i];
        m = m/N;
        printf("Medium of array A is : %.2f\n", m);
    }else{
        for(i=0; i<N; i++)         sum = sum + A[i];
        printf("Sum of array A is : %d\n", sum);
    }
    return 0;
}