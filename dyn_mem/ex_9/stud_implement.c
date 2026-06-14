#include "student.h"
#include <stdio.h>
#include <stdlib.h>

// Allocate memory for student n
Student* create_student_list(int n) {
    return (Student*)malloc(n * sizeof(Student));
}

// Enter data per student
void input_student(Student *s) {
    printf("Enter name: ");
    scanf("%49s", s->name); 
    printf("Enter age: ");
    scanf("%d", &s->age);
    printf("Enter grade: ");
    scanf("%f", &s->grade);
}

//  add student array
void input_students(Student *arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        input_student(&arr[i]);
    }
}

// print students array
void print_students(const Student *arr, int count) {
    printf("\nStudent List:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: Name: %s, Age: %d, Grade: %.f\n",
               i + 1, arr[i].name, arr[i].age, arr[i].grade);
    }
}

// add new 1 student (realloc)
Student* add_student(Student *arr, int *count) {
    Student *new_arr = (Student*)realloc(arr, (*count + 1) * sizeof(Student));
    if (new_arr == NULL) {
        printf("Reallocation failed\n");
        *count = -1;  
        return NULL;
    }
    (*count)++;
    return new_arr;
}

// free memory
void free_student_list(Student *arr) {
    free(arr);
}

