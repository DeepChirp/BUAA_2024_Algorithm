#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);
        int total = 1 << n; // 2^n
        int *p = (int *)malloc(total * sizeof(int));
        int *result = (int *)malloc(total * sizeof(int));

        for (int i = 0; i < total; ++i)
        {
            scanf("%d", &p[i]);
        }

        // find
        int *queue = (int *)malloc(total * sizeof(int));
        int *max_opponents = (int *)malloc(total * sizeof(int));

        for (int i = 0; i < total; ++i)
        {
            queue[i] = i;
            max_opponents[i] = 0;
        }

        int round_size = total;
        while (round_size > 1)
        {
            for (int i = 0; i < round_size / 2; i++)
            {
                int a = queue[2 * i];
                int b = queue[2 * i + 1];
                if (p[a] > p[b])
                {
                    queue[i] = a;
                    if (p[b] > max_opponents[a])
                        max_opponents[a] = p[b];
                    if (p[a] > max_opponents[b])
                        max_opponents[b] = p[a];
                }
                else
                {
                    queue[i] = b;
                    if (p[a] > max_opponents[b])
                        max_opponents[b] = p[a];
                    if (p[b] > max_opponents[a])
                        max_opponents[a] = p[b];
                }
            }
            round_size /= 2;
        }

        for (int i = 0; i < total; ++i)
        {
            result[i] = max_opponents[i];
        }

        for (int i = 0; i < total; ++i)
        {
            printf("%d ", result[i]);
        }
        putchar('\n');

        free(queue);
        free(max_opponents);
        free(p);
        free(result);
    }

    return 0;
}