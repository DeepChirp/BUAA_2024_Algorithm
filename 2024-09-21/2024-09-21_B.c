#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);
int lowerBound(int *arr, int n, long long target);
int upperBound(int *arr, int n, long long target);

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, (unsigned int)n, sizeof(int), cmp);

    for (int i = 0; i < q; i++)
    {
        int d, k;
        scanf("%d %d", &d, &k);
        long long lower = (long long)d * (long long)k;
        long long upper = lower + (long long)d - 1;

        int lowerIndex = lowerBound(a, n, lower);
        int upperIndex = upperBound(a, n, upper);

        int sum = upperIndex - lowerIndex;
        printf("%d\n", sum);
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int lowerBound(int *arr, int n, long long target)
{
    int left = 0, right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int upperBound(int *arr, int n, long long target)
{
    int left = 0, right = n;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}