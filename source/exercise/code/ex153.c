#include <stdio.h>

typedef struct workers{
    char name[20];
    int wage;
    int wdays;
}worker;

int main(){
    worker a, b;
    printf("Enter details of first worker\n");
    printf("--------------------------------");
    printf("\nEnter worker name: ");
    scanf("%s", a.name);
    printf("Enter wage         : ");
    scanf("%d", &a.wage);
    printf("Enter work days:   : ");
    scanf("%d", &a.wdays);
    printf("--------------------------------");
    printf("\nEnter details of second worker");
    printf("\n-------------------------------");
    printf("\nEnter worker name :");
    scanf("%s", b.name);
    printf("Enter wage          :");
    scanf("%d", &b.wage);
    printf("enter work days     :");
    scanf("%d", &b.wdays);
    printf("-------------------------\n");

    int p1 = a.wage * a.wdays;
    int p2 = b.wage * b.wdays;

    printf("Name of first worker: %s\nPayment of first worker: %d\n", a.name, p1);
    printf("\n--------------------------\n");
    printf("Name of second worker: %s\nPayment of second worker: %d\n", b.name, p2);

    return 0;
}