#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct goods
{
    int price;
    int weight;
};

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n, V;
        scanf("%d %d", &n, &V);
        struct goods *goods = malloc((unsigned int)n * sizeof(struct goods));
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d", &goods[j].price, &goods[j].weight);
        }
        int *dp = malloc((unsigned int)(V + 1) * sizeof(int));
        memset(dp, 0, (unsigned int)(V + 1) * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            for (int k = V; k >= goods[j].weight; k--)
            {
                dp[k] = MAX(dp[k], dp[k - goods[j].weight] + goods[j].price);
            }
        }
        printf("%d\n", dp[V]);
    }

    return 0;
}
