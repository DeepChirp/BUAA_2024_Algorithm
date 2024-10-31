#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[5005][5005];

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int length;
        char str[5005];
        scanf("%d", &length);
        scanf("%s", str);

        for (int len = 2; len <= length; len++)
        {
            for (int left = 0; left <= length - len; left++)
            {
                int right = left + len - 1;
                if (str[left] == str[right])
                {
                    dp[left][right] = dp[left + 1][right - 1];
                }
                else
                {
                    dp[left][right] = 1 + (dp[left + 1][right] < dp[left][right - 1] ? dp[left + 1][right] : dp[left][right - 1]);
                }
            }
        }

        printf("%d\n", length + dp[0][length - 1]);
    }

    return 0;
}