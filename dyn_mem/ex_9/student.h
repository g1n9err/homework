#ifndef STUDENT_H
#define STUDENT_H
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int age;
    float grade;
} Student;


Student* create_student_list(int n);
void input_student(Student *s);
void input_students(Student *arr, int count);
void print_students(const Student *arr, int count);
Student* add_student(Student *arr, int *count);
void free_student_list(Student *arr);

#endif

