#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

struct Goods
{
    size_t weight;
    uint64_t value;
};

int compare_goods(const void *a, const void *b)
{
    const struct Goods *ga = (const struct Goods *)a;
    const struct Goods *gb = (const struct Goods *)b;
    if (ga->weight < gb->weight)
    {
        return -1;
    }
    if (ga->weight > gb->weight)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        size_t n, W, k;
        scanf("%zu %zu %zu", &n, &W, &k);

        struct Goods *goods = malloc((n + 1) * sizeof(struct Goods));
        for (size_t i = 1; i <= n; i++)
        {
            scanf("%zu %llu", &goods[i].weight, &goods[i].value);
        }

        qsort(goods + 1, n, sizeof(struct Goods), compare_goods);

        uint64_t *cumulative_top_k_values = calloc(n + 2, sizeof(uint64_t));
        uint64_t *top_k_values = calloc(k + 2, sizeof(uint64_t));
        for (size_t i = n; i > 0; i--)
        {
            for (size_t j = 1; j <= k; j++)
            {
                if (goods[i].value > top_k_values[j])
                {
                    for (size_t v = k; v > j; v--)
                    {
                        top_k_values[v] = top_k_values[v - 1];
                    }
                    top_k_values[j] = goods[i].value;
                    break;
                }
            }
            for (size_t j = 1; j <= k; j++)
            {
                cumulative_top_k_values[i] += top_k_values[j];
            }
        }

        uint64_t *dp = calloc(W + 1, sizeof(uint64_t));
        uint64_t ans = cumulative_top_k_values[1];

        for (size_t i = 1; i <= n; i++)
        {
            size_t weight = goods[i].weight;
            uint64_t value = goods[i].value;
            for (size_t w = W; w >= weight; w--)
            {
                dp[w] = MAX(dp[w], dp[w - weight] + value);
                ans = MAX(ans, dp[w] + cumulative_top_k_values[i + 1]);
            }
        }

        printf("%lld\n", ans);

        free(dp);
        free(cumulative_top_k_values);
        free(top_k_values);
        free(goods);
    }

    return 0;
}
