#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int weight[n];
        memset(weight, 0, sizeof(weight));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &weight[j]);
        }
        qsort(weight, (unsigned int)n, sizeof(int), cmp);
        int left = 0, right = n - 1;
        int sum = 0;
        while (left < right)
        {
            if (weight[left] + weight[right] <= m)
            {
                left++;
                right--;
            }
            else
            {
                right--;
            }
            sum++;
        }
        if (left == right)
        {
            sum++;
        }
        printf("%d\n", sum);
    }

    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}