#include <stdio.h>
#include  <stdlib.h>
#include <unistd.h>

int** matrix(int x, int y);
void input_matrix(int **mat, int x, int y);
void output_matrix(int **mat,int x, int y);
long mull_matrix(int** mat, int x, int y);
int sum_matrix(int **mat, int x, int y);
void free_matrix(int **mat);