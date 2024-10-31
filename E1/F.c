#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long num[10000][10000];

long long combination(long long n, long long m);
long long intPow(long long base, long long exp);

int main()
{
    long long t;
    scanf("%lld", &t);
    for (long long i = 0; i < t; i++)
    {
        long long n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        long long extra = m - 2 * k;
        if (extra < 0 || n < k || extra > n - k)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n", (((combination(n, k) % MOD) * (combination(n - k, extra) % MOD) % MOD) * (intPow(2, extra) % MOD) % MOD));
        }
    }

    return 0;
}

long long combination(long long n, long long m)
{
    if (m == 0 || n == m)
    {
        return 1;
    }
    else if(num[n][m] != 0)
    {
        return num[n][m];
    }
    else
    {
        long long result = (combination(n - 1, m - 1) + combination(n - 1, m)) % MOD;
        num[n][m] = result;
        return result;
    }
}

long long intPow(long long base, long long exp)
{
    long long result = 1;
    for (long long i = 0; i < exp; i++)
    {
        result = result * base % MOD;
    }
    return result;
}