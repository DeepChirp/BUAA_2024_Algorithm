#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        int location;
        scanf("%d %d", &n, &location);
        location--;
        int a[n], b[n];
        long long dp[n];
        long long value[n];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(dp, 0, sizeof(dp));
        memset(value, 0, sizeof(value));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &b[j]);
        }

        int m;
        scanf("%d", &m);
        int max_index = -1;
        int second_max_index = -1;

        for (int j = 0; j < m; j++)
        {
            int mission;
            scanf("%d", &mission);
            mission--;

            if (j == 0)
            {
                dp[mission] = (mission == location) ? a[mission] : b[mission];
                max_index = mission;
            }
            else
            {
                if (mission == max_index)
                {
                    if (second_max_index == -1)
                    {
                        dp[mission] = MAX(dp[mission] + a[mission], b[mission]);
                    }
                    else
                    {
                        dp[mission] = MAX(dp[mission] + a[mission], dp[second_max_index] + b[mission]);
                    }
                }
                else
                {
                    if (dp[mission] == 0)
                    {
                        dp[mission] = (mission == location) ? MAX(dp[max_index] + b[mission], a[mission]) : dp[max_index] + b[mission];
                    }
                    else
                    {
                        dp[mission] = MAX(dp[mission] + a[mission], dp[max_index] + b[mission]);
                    }
                    if (dp[mission] > dp[max_index])
                    {
                        second_max_index = max_index;
                        max_index = mission;
                    }
                    else if (dp[mission] > dp[second_max_index])
                    {
                        second_max_index = mission;
                    }
                }
            }
        }

        long long max = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            max = MAX(max, dp[j]);
        }
        printf("%lld\n", max);
    }

    return 0;
}
