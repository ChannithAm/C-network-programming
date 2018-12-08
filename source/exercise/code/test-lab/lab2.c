#include <stdio.h>

int main(){
    int i, j, n=0, tmp, A[7];
    for(i=0; i<7; i++){
        printf("A[%d] : ", i+1);
        scanf("%d", &tmp);
        if(tmp == 0) break;
        else A[i] = tmp;
        n++;
    }
    if(n==0) printf("\nThe array A has no element!!!");
    else{
        printf("\nThe array A is : ");
        for(i=0; i<n; i++) printf("%d\t", A[i]);
        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++){
                if(A[i] > A[j]){
                    tmp = A[i];
                    A[i] =  A[j];
                    A[j] = tmp;
                }
            }
        printf("\nArray after re-arange (increase): ");
        for(i=0; i<n; i++) printf("%d\t", A[i]);
    }
    printf("\n");
    return 0;
}