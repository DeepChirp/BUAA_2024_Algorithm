#include <stdio.h>
#include <stdlib.h>

long long **matrix_multiply(long long **matrix_A, long long **matrix_B, int n)
{
    long long **matrix_result = (long long **)malloc(n * sizeof(long long *));
    for (int i = 0; i < n; i++)
    {
        matrix_result[i] = (long long *)malloc(n * sizeof(long long));
    }

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            matrix_result[j][k] = 0;
            for (int l = 0; l < n; l++)
            {
                matrix_result[j][k] += matrix_A[j][l] * matrix_B[l][k];
            }
        }
    }

    return matrix_result;
}

void free_matrix(long long **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        long long **matrix_A = (long long **)malloc(n * sizeof(long long *));
        long long **matrix_B = (long long **)malloc(n * sizeof(long long *));
        for (int j = 0; j < n; j++)
        {
            matrix_A[j] = (long long *)malloc(n * sizeof(long long));
            for (int k = 0; k < n; k++)
            {
                scanf("%lld", &matrix_A[j][k]);
            }
        }

        for (int j = 0; j < n; j++)
        {
            matrix_B[j] = (long long *)malloc(n * sizeof(long long));
            for (int k = 0; k < n; k++)
            {
                scanf("%lld", &matrix_B[j][k]);
            }
        }

        long long **origin_matrix_result = matrix_multiply(matrix_A, matrix_B, n);
        long long **matrix_result = matrix_multiply(matrix_A, matrix_B, n);

        for (int j = 1; j < m; j++)
        {
            long long **temp = matrix_multiply(matrix_result, origin_matrix_result, n);
            free_matrix(matrix_result, n);
            matrix_result = temp;
        }

        // print
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                printf("%lld", matrix_result[j][k]);
                if (k < n - 1)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        free_matrix(matrix_A, n);
        free_matrix(matrix_B, n);
        free_matrix(matrix_result, n);
    }

    return 0;
}