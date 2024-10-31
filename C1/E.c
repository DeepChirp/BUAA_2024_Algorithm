#include <stdio.h>

#define MOD 10007

int evaluatePolynomial(int degree, int coefficients[], int x)
{
    int result = 0;
    for (int i = degree; i >= 0; i--)
    {
        result = (result * x + coefficients[i]) % MOD;
    }
    return result;
}

int main()
{
    int n, m, q;

    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    int b[m + 1];
    for (int i = 0; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }

    scanf("%d", &q);
    int Xi, Yi;

    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &Xi, &Yi);
        int fx = evaluatePolynomial(n, a, Xi);
        int fy = evaluatePolynomial(m, b, Yi);
        int result = (fx * fy) % MOD;
        printf("%d\n", result);
    }

    return 0;
}