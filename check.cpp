#include "stdio.h"

long int fact(long int n);

int main() {
    long int n;
    scanf("%ld", &n);

    if (n == 0) {
        printf("%ld", 1);
        return 0;
    }

    printf("%ld \n", fact(n));
    return 0;
}

long int fact(long int n) {
    if (n >= 1)
        return n*fact(n-1);
    else
        return 1;
}




// #include <stdio.h>

// struct Student {
//     char name[50];
//     int roll;
//     float marks;
// };

// int main() {
//     struct Student s;

//     printf("Enter information of students:\n");

//     printf("Enter name: ");
//     scanf("%s", s.name);

//     printf("Enter roll number: ");
//     scanf("%d", &s.roll);

//     printf("Enter marks: ");
//     scanf("%f", &s.marks);

//     // Print student details
//     printf("Displaying Information:\n");
//     printf("Name: %s\n", s.name);
//     printf("Roll: %d\n", s.roll);
//     printf("Marks: %.2f\n", s.marks);

//     return 0;
// }