#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define FIB 39

int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155}; // total: 39

int
main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n, w;
        scanf("%d %d", &n, &w);

        int a[MAX];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int dp[MAX + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {

            }

        }

        int max_books = dp[n];
        for (int i = 1; i <= n; i++)
        {
            max_books = max(max_books, dp[i]);
        }

        printf("%d\n", max_books);
    }

    return 0;
}