#include <stdio.h>

int main()
{
    int i, N;
    int j=0;
    float max;
    float A[10];
    do{
        printf("Enter N = ");
        scanf("%d", &N);
    }while(N<= 0 || N>=10);
    printf("\nEnter Array A: \n");
    for(i=0; i<N; i++){
        printf("A[%d] \t: ", i+1);
        scanf("%f", &A[i]);
    }
    printf("The array of A is : ");
    for(i=0; i<N; i++) printf("%.2f\t", A[i]);
    max = A[0];
    for(i=0; i<N; i++){
        if(max == A[i])
            j++;
        if(max < A[i])
            {max = A[i]; j=1;}
    }
    printf("\nThe maximum of Array is %.2f", max);
    printf("\nThe number equal to max are : %d", j);
    printf("\n\n");
    return 0;
}
