#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("invalid number\n");
        return 1;
    }

    // allocate memory for students
    Student *students = create_student_list(n);
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    if (n > 0) {
        input_students(students, n);
        print_students(students, n);
    } else {
        printf("No students initially.\n");
    }

    // realloc add 1 new student
    printf("\nAdding a new student:\n");
    Student *new_students = add_student(students, &n);
    if (new_students == NULL) {
        if (students != NULL) free(students);
        return 1;
    }
    students = new_students;

    // enter new student data 
    printf("Enter data for new student (Student %d):\n", n);
    input_student(&students[n - 1]);

    // printf new array
    print_students(students, n);

    // free memory
    free_student_list(students);

    return 0;
}