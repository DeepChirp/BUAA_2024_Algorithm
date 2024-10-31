#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long max(long long a, long long b);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        long long value[n];
        long long dp[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &value[j]);
        }
        if (n == 1)
        {
            printf("%lld\n", value[0]);
            continue;
        }
        dp[0] = value[0];
        dp[1] = max(value[0], value[1]);
        for (int j = 2; j < n; j++)
        {
            dp[j] = max(dp[j - 1], dp[j - 2] + value[j]);
        }
        printf("%lld\n", dp[n - 1]);
    }

    return 0;
}

long long max(long long a, long long b)
{
    return a > b ? a : b;
}