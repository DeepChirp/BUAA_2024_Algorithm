#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        int max = INT_MIN;
        int second_max = INT_MIN;
        int current;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &current);
            if (current > max)
            {
                second_max = max;
                max = current;
            }
            else if (current > second_max)
            {
                second_max = current;
            }
        }
        printf("%d\n", max + second_max);
    }

    return 0;
}
