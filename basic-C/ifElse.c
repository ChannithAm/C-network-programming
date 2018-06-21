#include <stdio.h>

int main(){
    // khai bao mot so dai dien cho tuoi cua ban
    int age;

    printf("Please enter your age: \n");
    // input from key board
    scanf("%d", &age);

    // check your age
    if(age < 80){
        printf("You are pretty young.");
    }
    else if(age >= 80 && age <= 100){
        printf("You are old.");
    }
    else{
        printf("You are very old!");
    }

    return 0;
}