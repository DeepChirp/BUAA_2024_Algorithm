#include <stdio.h>
#include <stdlib.h>

int result[20][20];

int f(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return f(m - 1, 1);
    }
    else if (m > 0 && n > 0)
    {
        return f(m - 1, f(m, n - 1));
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        result[m][n] = f(m, n);
        printf("%d\n", result[m][n]);
    }

    return 0;
}
