#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b);
int gcd(int a, int b);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        qsort(a, (unsigned int)n, sizeof(int), cmp);
        for (int j = 0; j < 2; j++)
        {
            int sum = 1;
            for (int k = 1; k < n; k++)
            {
                if (a[k] % a[0] == 0)
                {
                    a[k] = INT_MAX;
                    sum++;
                }
            }
            a[0] = INT_MAX;
            qsort(a, (unsigned int)n, sizeof(int), cmp);
            n -= sum;
            if (n == 0)
            {
                break;
            }
        }
        if (n == 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}