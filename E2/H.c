#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dp[100005];
char str[100005];

char T[] = "1145141919810"; // length = 13
const int LENGTH = 13;

int calculateSameChar(int left, int right);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        memset(dp, 0, sizeof(dp));
        memset(str, '\0', sizeof(str));
        scanf("%s", str);
        int length = (int)strlen(str);
        for (int j = 0; j < length; j++)
        {
            for (int k = j - 1; k >= MAX(0, j - LENGTH) - 1; k--)
            {
                if (k == -1 && j <= LENGTH)
                {
                    dp[j] = MAX(dp[j], calculateSameChar(0, j)); // assume dp[-1] = 0
                }
                else
                {
                    dp[j] = MAX(dp[j], dp[k] + calculateSameChar(k + 1, j));
                }
            }
        }
        printf("%d\n", dp[length - 1]);
    }

    return 0;
}

int calculateSameChar(int left, int right)
{
    int sum = 0;
    int index = 0;
    while (left + index <= right)
    {
        if (str[left + index] == T[index])
        {
            sum++;
        }
        index++;
    }
    return sum;
}
