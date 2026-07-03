#include "matrix.h"


int** (*matrix_ptr)(int, int) = NULL;
void (*input_matrix_ptr)(int**, int, int) = NULL;
void (*output_matrix_ptr)(int**, int, int) = NULL;
long (*mull_matrix_ptr)(int**, int, int) = NULL;
int (*sum_matrix_ptr)(int**, int, int) = NULL;
void (*free_matrix_ptr)(int**, int) = NULL;

void *lib_handle = NULL;

void load_library() {
    lib_handle = dlopen("./libmatrix.so", RTLD_LAZY);
    if (!lib_handle) {
        printf("Error loading library: %s\n", dlerror());
        exit(1);
    }

    matrix_ptr        = (int** (*)(int, int)) dlsym(lib_handle, "matrix");
    input_matrix_ptr  = (void (*)(int**, int, int)) dlsym(lib_handle, "input_matrix");
    output_matrix_ptr = (void (*)(int**, int, int)) dlsym(lib_handle, "output_matrix");
    mull_matrix_ptr   = (long (*)(int**, int, int)) dlsym(lib_handle, "mull_matrix");
    sum_matrix_ptr    = (int (*)(int**, int, int)) dlsym(lib_handle, "sum_matrix");
    free_matrix_ptr   = (void (*)(int**, int)) dlsym(lib_handle, "free_matrix");

    char *error = dlerror();
    if (error != NULL) {
        printf("Error binding functions: %s\n", error);
        dlclose(lib_handle);
        exit(1);
    }
}

void unload_library() {
    if (lib_handle) {
        dlclose(lib_handle);
    }
}

int main() {

    load_library();

    int rows;
    int cols;

    printf("Enter rows: "); 
    scanf("%d", &rows);
    printf("Enter cols: "); 
    scanf("%d", &cols);


    int **arr = matrix_ptr(rows, cols);
    if (!arr) {
        printf("memory error:\n");
        return 1;
    }

    input_matrix_ptr(arr, rows, cols);
    printf("\n");
    output_matrix_ptr(arr, rows, cols);

    printf("\nsum = %d\n", sum_matrix_ptr(arr, rows, cols));
    printf("mull = %ld\n", mull_matrix_ptr(arr, rows, cols));


    free_matrix_ptr(arr, rows);

    unload_library();

    return 0;
}
   
