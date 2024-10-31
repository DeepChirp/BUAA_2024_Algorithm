#include <stdio.h>
#include <stdlib.h>

long long min(long long a, long long b, long long c);

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int m;
        scanf("%d", &m);
        long long time_a[m], time_b[m], time_c[m];
        long long time_transfer[3][m];
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &time_a[j]);
        }
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &time_b[j]);
        }
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &time_c[j]);
        }
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                scanf("%lld", &time_transfer[j][k]);
            }
        }

        long long dp[2][3];
        dp[0][0] = time_a[0];
        dp[0][1] = time_b[0];
        dp[0][2] = time_c[0];
        int j;

        for (j = 1; j < m; j++)
        {
            dp[j & 1][0] = min(dp[(j - 1) & 1][0] + time_transfer[0][0], dp[(j - 1) & 1][1] + time_transfer[1][0], dp[(j - 1) & 1][2] + time_transfer[2][0]) + time_a[j];
            dp[j & 1][1] = min(dp[(j - 1) & 1][0] + time_transfer[0][1], dp[(j - 1) & 1][1] + time_transfer[1][1], dp[(j - 1) & 1][2] + time_transfer[2][1]) + time_b[j];
            dp[j & 1][2] = min(dp[(j - 1) & 1][0] + time_transfer[0][2], dp[(j - 1) & 1][1] + time_transfer[1][2], dp[(j - 1) & 1][2] + time_transfer[2][2]) + time_c[j];
        }

        printf("%lld\n", min(dp[(j - 1) & 1][0], dp[(j - 1) & 1][1], dp[(j - 1) & 1][2]));
    }

    return 0;
}

long long min(long long a, long long b, long long c)
{
    if (a < b)
    {
        if (a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b < c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}