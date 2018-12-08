#include <stdio.h>
#include <stdlib.h>


int main(){
    float score;

    tt : printf("Enter data:\n");
    printf("Enter the student's score: ");
    scanf("%f", &score);

    if((score >= 0) && (score <= 3)) printf("Very poor");
    else if( score == 4) printf("Poor");
    else if((score  >= 5) && (score <= 6)) printf("Faire");
    else if((score >=7) && (score <= 8)) printf("Pretty good");
    else if((score >=9) && (score <= 10)) printf("Very good");
    else printf("Entered wrong!!!\n");

    printf("\nContinue type 1 / stop type 0: ");
    scanf("%f", &score);
    if(score == 1) goto tt;
    else
        printf("Bye!\n");


}