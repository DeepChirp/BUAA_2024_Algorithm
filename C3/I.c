#include <stdio.h>
#include <string.h>

#define MAX 100005

long long dp[MAX][5]; // 1=b, 2=bu, 3=bua, 4=buaa

int main()
{
    char s[MAX];
    scanf("%s", s);
    memset(dp, 0, sizeof(dp));
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            for (int j = 1; j <= 4; j++)
            {
                dp[i][j] = dp[i - 1][j]; // copy previous state
            }
        }
        if (s[i] == 'b')
        {
            dp[i][1] = dp[i][1] + 1;
        }
        if (s[i] == 'u')
        {
            dp[i][2] = dp[i][2] + dp[i - 1][1];
        }
        if (s[i] == 'a')
        {
            dp[i][3] = dp[i][3] + dp[i - 1][2];
            dp[i][4] = dp[i][4] + dp[i - 1][3];
        }
    }
    printf("%lld\n", dp[n - 1][4]);
    return 0;
}