#include <stdio.h>
#include <stdlib.h>

long long merge(int *arr, int *temp, int left, int mid, int right, int k)
{
    int i = left;
    int j = mid + 1;
    int pos = left;
    long long count = 0;

    for (i = left; i <= mid; i++)
    {
        while (j <= right && arr[i] > (long long)k * arr[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    i = left;
    j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[pos++] = arr[i++];
        }
        else
        {
            temp[pos++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[pos++] = arr[i++];
    }
    while (j <= right)
    {
        temp[pos++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}

long long merge_sort(int *arr, int *temp, int left, int right, int k)
{
    long long count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        count += merge_sort(arr, temp, left, mid, k);
        count += merge_sort(arr, temp, mid + 1, right, k);

        count += merge(arr, temp, left, mid, right, k);
    }
    return count;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long result = merge_sort(arr, temp, 0, n - 1, k);

    printf("%lld\n", result);

    free(arr);
    free(temp);

    return 0;
}
