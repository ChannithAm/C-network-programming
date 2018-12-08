#include <stdio.h>

struct player{
    char name[50];
    int runs;
};

int main(int argc, char const *argv[])
{
    int i, s=0;
    struct player a[11]; // a[11] - number of players
    printf("Enter name of player runs scored\n");
    printf("===================================\n\t");
    for(i=0; i<11; i++){
        scanf("%s", a[i].name);
        scanf("%d", &a[i].runs);
        printf("\t");
    }

    for(i=0; i<11; i++)
        s = s + a[i].runs;
    printf("\n==================================\n");
    printf("Total runs scored by Team: %d\n", s);

    return 0;
}
