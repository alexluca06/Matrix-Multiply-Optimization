#include <stdio.h>
#include <stdlib.h>

/*
    Optimization vector access and caching
*/
void multiply(int* matrix1, int *matrix2, int* result, int N)
{
    int i, j, k;
    // Make the multiply
    for (i = 0; i < N; ++i) {
        int* pointer_to_result = result + i * N;
        for (k = 0; k < N; ++k) {
            int* pointer_to_matrix2 = matrix2 + k * N;
            register const int vector_matrix1 = matrix1[i * N + k];
            for (j = 0; j < N; ++j) {
                pointer_to_result[j] += vector_matrix1 * pointer_to_matrix2[j];
            }
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