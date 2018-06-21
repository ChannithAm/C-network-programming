#include<stdio.h>

int main(){
    // De nghi nguoi dung chon 1 lua chon
    printf("Please select one optin:\n");
    printf("1 - Play a game\n");
    printf("2 - Play musci\n");
    printf("3 - Shutdown computer \n");

    // khai bao mot bien 'option'
    int optin;

    // Ham scanf se doi ban go vao mot doan text tu ban phim
    // va nhan enter de hoan thanh
    scanf("%d", &optin);

    // Kiem tra
    switch(optin){
        case 1:
            printf("You choose to play the game\n");
            break;
        case 2:
            printf("You choose to play the music \n");
            break;
        case 3:
            printf("You choose to shutdown the computer\n");
            break;
        default:
            printf("Nothing to do ... \n");
            break;
    }
    return 0;
}