#ifndef MATRIX_H
#define MATRIX_H


#include <stdio.h>
#include  <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

int** matrix(int, int);
void input_matrix(int **, int, int);
void output_matrix(int **,int, int);
long mull_matrix(int**, int, int);
int sum_matrix(int **, int, int);
void free_matrix(int **, int);

#endif
