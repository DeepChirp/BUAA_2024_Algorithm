#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int dp[2][10000];

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        long long A;
        scanf("%d%lld", &n, &A);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dp[0][j]);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dp[1][j]);
        }
        int result = 0;
        for (int j = 0; j < n; j++)
        {
            int max = (long long)MAX(dp[0][j], dp[1][j]);
            int min = (long long)MIN(dp[0][j], dp[1][j]);
            if (A < min)
            {
                break;
            }
            else
            {
                result++;
                if (A < max)
                {
                    A += min;
                }
                else
                {
                    if (min > 0)
                    {
                        A += (min + max);
                    }
                    else
                    {
                        A += max;
                    }
                }
            }
        }
        printf("%d\n", result);
    }

    return 0;
}
