#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100005
#define MOD 998244353

long long result[MAX];

int main()
{
    result[0] = 1;
    result[2] = 3;
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        if (n % 2 != 0)
        {
            printf("0\n");
            continue;
        }
        else if (result[n] != 0)
        {
            printf("%lld\n", result[n]);
            continue;
        }
        for (int j = 2; j <= n / 2; j += 2)
        {
            result[n] += ((((result[j] % MOD) * (result[n - j] % MOD) % MOD) + (((result[j - 2] % MOD) * (result[n - j - 2] % MOD) * 2) % MOD)) % MOD);
        }
        printf("%lld\n", result[n] % MOD);
    }

    return 0;
}
