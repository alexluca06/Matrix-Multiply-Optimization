#include <stdio.h>
#include <stdlib.h>


void multiply(int* matrix1, int *matrix2, int* result, int N)
{
    int i, j, k;
    // Make the multiply
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {
                result[i * N + j] += matrix1[i * N + k] * matrix2[k * N + j];
            }
        }
    }
    // Print the result
    printf("The result of matrix1 * matrix2 is:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%d ", result[i*N + j]);
        }
        printf("\n");
    }
}

int main(void)
{

    int** matrix1;
    int* matrix2, *result;
    const int N = 256;
    // Liniar declaration(like vectors: int*) vs normal declaration(int**)

    matrix1 = calloc(N, sizeof(int));
    for (int i = 0; i < N; ++i) {
        matrix1[i] = calloc(N, sizeof(int));
    }

    matrix2 = calloc(N*N, sizeof(int)); //much better: cache optimization

    /* 

        Access items: matrix1[i][j] vs matrix2[N * i + j]
                      v[i] <=> *(v + i);
                      a[i * n] <=> *(a + i * n);

    */

    //Testing code: time ./a.out
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