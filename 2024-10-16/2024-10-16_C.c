#include <stdio.h>
#include <stdlib.h>

#define MAX 36

int main()
{
    int n;
    scanf("%d", &n);
    long long way[MAX] = {0};
    way[1] = 1;

    printf("n  : P(n)\n");

    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            way[i] = 0;
            for (int j = 1; j < i; j++)
            {
                way[i] += way[j] * way[i - j];
            }
        }
        printf("%-3d: %lld\n", i, way[i]);
    }

    return 0;
}