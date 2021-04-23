#include <stdio.h>
#include <stdlib.h>

/*
    Optimization of constants and access to vectors using linearized matrices.  
*/
void multiply(int* matrix1, int *matrix2, int* result, int N)
{
    int i, j, k;
    // Make the multiply
    for (i = 0; i < N; ++i) {
        // This operation not depends of j or k: they remain in cache
        int* pointer_to_matrix1 = matrix1 + i * N;
        int* pointer_to_result = result + i * N;
        for (j = 0; j < N; ++j) {
            register int sum = 0;  // to avoid accessing the same cell from result multiple times 
            for (k = 0; k < N; ++k) {
                sum += pointer_to_matrix1[k] * matrix2[k * N + j];
            }
            pointer_to_result[j] = sum;
        }
    }
    // Print the result
    printf("The result of matrix1 * matrix2 is:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%d ", result[i*N +j]);
        }
        printf("\n");
    }
}

int main(void)
{
    //Testing code: time ./a.out
    const int N = 256;
    int* a = calloc(N*N, sizeof(int));
    int* b = calloc(N*N, sizeof(int));
    int* c = calloc(N*N, sizeof(int));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i*N + j] = rand() % 100;
            b[i*N + j] = rand() % 100;
        }
    }
    multiply(a, b, c, N);
    return 0;
}