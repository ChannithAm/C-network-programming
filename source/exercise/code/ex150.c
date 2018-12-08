#include <stdio.h>

struct employee{
    int e;
    char name[20];
    char designation[20];
    char depth[20];
    int sal;
};

int main(){
    struct employee a;
    printf("Enter employee details: \n");
    printf("-----------------------------------\n");
    printf("Enter employee-id: ");
    scanf("%d", &a.e);
    printf("Enter name  :");
    scanf("%s", a.name);
    printf("Enter designation : ");
    scanf("%s", a.designation);
    printf("Enter department: ");
    scanf("%s", a.depth);
    printf("Enter salary        : ");
    scanf("%d", &a.sal);

    printf("---------------------------------");
    printf("\nEmployee details:\n");
    printf("---------------------------------\n");
    printf("Name        : %s\n", a.name);
    printf("Designation : %s\n", a.designation);
    printf("Department  : %s\n", a.depth);
    printf("Salary      : %d\n", a.sal);

    return 0;
}
