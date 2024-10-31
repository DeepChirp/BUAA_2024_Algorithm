#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100005

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        int a[MAX];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int count[MAX] = {0};
        int uniqueCount = 0;
        int left = 0, minLen = n + 1, minLeft = -1, minRight = -1;

        for (int right = 0; right < n; right++)
        {
            if (count[a[right]] == 0)
            {
                uniqueCount++;
            }
            count[a[right]]++;

            while (uniqueCount == k)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    minLeft = left;
                    minRight = right;
                }
                count[a[left]]--;
                if (count[a[left]] == 0)
                {
                    uniqueCount--;
                }
                left++;
            }
        }

        if (minLeft == -1)
        {
            printf("N0\n");
        }
        else
        {
            printf("%d %d\n", minLeft + 1, minRight + 1);
        }
    }

    return 0;
}