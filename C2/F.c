#include <stdio.h>
#include <stdlib.h>

#define N 5000005

int a[N];

int nextRand();
int cmp(const void *a, const void *b);

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            a[i] = nextRand();
        }
        qsort(a + 1, n, sizeof(int), cmp);
        long long result = 0;
        int order = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i > 1 && a[i] == a[i - 1])
            {
                result += (long long)(a[i] * order);
            }
            else
            {
                order = i;
                result += (long long)(a[i] * order);
            }
        }
        printf("%lld\n", result);
    }
    return 0;
}

int nextRand()
{
    static unsigned int rnd_num = 0x80000001;
    static int mod = 1e5 + 3;

    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    return rnd_num % mod;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}