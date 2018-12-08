#include <stdio.h>

int main(){
    int score;

    tt: printf("Enter student's data\n");
    printf("Score: "); scanf("%d", &score);

    switch(score){
        case 0:
        case 1:
        case 2:
        case 3: printf("Very poor");
                break;
        case 4: printf("Poor");
                break;
        case 5:
        case 6: printf("Fair");
                break;
        case 7:
        case 8: printf("Good");
                break;
        case 9:
        case 10: printf("Very good");
                break;
        default: printf("Number not valid!!!");
    }

    printf("\nTo be continue, type 1 /stop, type 0: ");
    scanf("%d", &score);

    if(score == 1) goto tt;
    else printf("\nBye!\n");

    return 0;
}