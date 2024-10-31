#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, (unsigned int)n, sizeof(int), cmp);

    int lowerIndex = 0;
    int upperIndex = 0;
    int sum = 0;
    int max = INT_MIN;

    while (upperIndex < n)
    {
        if (a[upperIndex] - a[lowerIndex] <= k)
        {
            sum += a[upperIndex];
            upperIndex++;
        }
        else
        {
            sum -= a[lowerIndex];
            lowerIndex++;
        }
        if (sum > max)
        {
            max = sum;
        }
    }

    printf("%d\n", max);
    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}