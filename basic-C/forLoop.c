#include <stdio.h>

/*
 Tao mot bien x va gan gia tri ban dau cua no la 2
 - Dieu kien kiem tra la x <15
 - Neu x < 15 dung thi khoi lenh duoc chay
 - Sau moi buoc lap (iteration) tang gia tri cua x duoc
 tang them 3.
*/
int main(){
    printf("For loop example.\n");

    for(int x=2; x<15; x += 3){
        printf("\n");
        printf("Value of x = %d \n" ,x);
        fflush(stdout);
    }

    return 0;
}