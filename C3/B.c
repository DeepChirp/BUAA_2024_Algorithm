#include <stdio.h>
#include <stdlib.h>

struct dp
{
    long long value;
    int position;
};

int main()
{
    int length;
    scanf("%d", &length);
    int price[length];
    struct dp dp[length + 1];

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &price[i]);
    }

    dp[0].value = 0;
    dp[0].position = -1; // -1 means no cut

    for (int i = 1; i <= length; i++)
    {
        dp[i].value = price[i - 1];
        dp[i].position = -1;
        for (int j = 1; j < i; j++)
        {
            if (dp[j].value + price[i - j - 1] > dp[i].value)
            {
                dp[i].value = dp[j].value + price[i - j - 1];
                dp[i].position = j;
            }
        }
    }

    printf("%lld\n", dp[length].value);

    int segments[length];
    int k = 0;
    int current_length = length;
    while (current_length > 0)
    {
        if (dp[current_length].position == -1)
        {
            segments[k++] = current_length;
            break;
        }
        else
        {
            segments[k++] = current_length - dp[current_length].position;
            current_length = dp[current_length].position;
        }
    }

    printf("%d\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", segments[i]);
    }
    printf("\n");

    return 0;
}