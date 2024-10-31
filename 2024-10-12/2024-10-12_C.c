#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MOD 998244353

int main()
{
    unsigned int n, m, k;
    scanf("%u %u %u", &n, &m, &k);
    bool isTrapped[n];
    memset(isTrapped, false, sizeof(isTrapped));
    for (int i = 0; i < (int)m; i++)
    {
        int level;
        scanf("%d", &level);
        isTrapped[level - 1] = true;
    }
    unsigned long long result = 1;
    unsigned long long normalWays = 1;
    unsigned long long trappedWays = isTrapped[0] ? 0 : 1;
    for (int i = 1; i < (int)n; i++)
    {
        unsigned long long newNormalWays = (k - 2) * normalWays + trappedWays;
        trappedWays = isTrapped[i] ? 0 : normalWays * (k - 1) % MOD;
        normalWays = newNormalWays % MOD;
    }
    result = (normalWays * (k - 1) + trappedWays) % MOD;
    printf("%llu\n", result);

    return 0;
}
