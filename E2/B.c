#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long matrix[1000][1000];
long long dp[1000][1000];

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        memset(matrix, 0, sizeof(matrix));
        memset(dp, 0, sizeof(dp));

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                scanf("%lld", &matrix[j][k]);
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (j == 0)
                {
                    if (k == 0)
                    {
                        dp[j][k] = matrix[j][k];
                    }
                    else
                    {
                        dp[j][k] = dp[j][k - 1] + matrix[j][k];
                    }
                }
                else if (k == 0)
                {
                    dp[j][k] = dp[j - 1][k] + matrix[j][k];
                }
                else
                {
                    dp[j][k] = matrix[j][k] + MAX(dp[j - 1][k], dp[j][k - 1]);
                }
            }
        }
        printf("%lld\n", dp[n - 1][m - 1]);
    }

    return 0;
}