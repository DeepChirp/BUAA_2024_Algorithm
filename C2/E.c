#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        long long matrix_A[n][n];
        long long matrix_B[n][n];
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%lld", &matrix_A[j][k]);
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%lld", &matrix_B[j][k]);
            }
        }

        // multiply A and B
        long long matrix_result[n][n];
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

    }

    return 0;
}
