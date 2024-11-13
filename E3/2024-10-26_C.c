#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

struct goods
{
    long long weight;
    int value;
};

int main()
{
    int n;
    long long V;
    scanf("%d %lld", &n, &V);

    struct goods *goods = malloc((unsigned int)n * sizeof(struct goods));

    int total_value = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %d", &goods[i].weight, &goods[i].value);
        total_value += goods[i].value;
    }

    long long *dp = malloc((unsigned int)(total_value + 1) * sizeof(long long));
    memset(dp, LLONG_MAX, (unsigned int)(total_value + 1) * sizeof(long long));
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        long long weight = goods[i].weight;
        int value = goods[i].value;
        for (int v = total_value; v >= value; v--)
        {
            if (dp[v - value] != LLONG_MAX)
            {
                dp[v] = MIN(dp[v], dp[v - value] + weight);
            }
        }
    }

    int max_value = 0;
    for (int i = total_value; i >= 0; i--)
    {
        if (dp[i] <= V)
        {
            max_value = i;
            break;
        }
    }

    printf("%d\n", max_value);

    free(goods);
    free(dp);

    return 0;
}
