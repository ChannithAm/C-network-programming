// Stroe information and display of a student using structure
/**
 * This program stores the information (name, roll and marks) of
 * a student and display it on the screen using structure
 * 
*/

#include <stdio.h>

struct Student{
    char name[50];
    int roll;
    float marks;
};

int main(int argc, char const *argv[])
{
    struct Student s;

    printf("Enter information:\n");
    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("\n\nDisplaying information:\n");
    printf("Name: ");
    puts(s.name);
    printf("Roll number: %d\n", s.roll);
    printf("Marks: %.1f\n", s.marks);
    return 0;
}
