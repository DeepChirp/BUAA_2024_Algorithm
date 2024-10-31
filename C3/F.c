#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 2001

int longest_common_substring(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[MAX_LEN][MAX_LEN];
    int max_len = 0;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_len)
                {
                    max_len = dp[i][j];
                }
            }
        }
    }
    return max_len;
}

int longest_common_subsequence(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int dp[MAX_LEN][MAX_LEN];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[len1][len2];
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        char s1[MAX_LEN], s2[MAX_LEN];
        scanf("%s", s1);
        scanf("%s", s2);

        int lcs_str = longest_common_substring(s1, s2);
        int lcs_seq = longest_common_subsequence(s1, s2);

        printf("%d %d\n", lcs_str, lcs_seq);
    }

    return 0;
}
