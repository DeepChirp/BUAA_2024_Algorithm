#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

struct polynomial
{
    long long coefficient;
    int degree;
};

int n, m;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        struct polynomial *polynomialA = (struct polynomial *)malloc(sizeof(struct polynomial) * MAX);
        struct polynomial *polynomialB = (struct polynomial *)malloc(sizeof(struct polynomial) * MAX);

        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &polynomialA[j].coefficient);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &polynomialA[j].degree);
        }
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &polynomialB[j].coefficient);
        }
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &polynomialB[j].degree);
        }

        // merge
        struct polynomial *mergedPolynomial = (struct polynomial *)malloc(sizeof(struct polynomial) * (n + m));

        int j = 0, k = 0, l = 0;
        while (j < n && k < m)
        {
            if (polynomialA[j].degree < polynomialB[k].degree)
            {
                mergedPolynomial[l].coefficient = polynomialA[j].coefficient;
                mergedPolynomial[l].degree = polynomialA[j].degree;
                j++;
                l++;
            }
            else if (polynomialA[j].degree > polynomialB[k].degree)
            {
                mergedPolynomial[l].coefficient = polynomialB[k].coefficient;
                mergedPolynomial[l].degree = polynomialB[k].degree;
                k++;
                l++;
            }
            else
            {
                mergedPolynomial[l].coefficient = polynomialA[j].coefficient + polynomialB[k].coefficient;
                mergedPolynomial[l].degree = polynomialA[j].degree;
                j++;
                k++;
                if (mergedPolynomial[l].coefficient != 0)
                {
                    l++;
                }
            }
        }
        while (j < n)
        {
            mergedPolynomial[l].coefficient = polynomialA[j].coefficient;
            mergedPolynomial[l].degree = polynomialA[j].degree;
            j++;
            l++;
        }
        while (k < m)
        {
            mergedPolynomial[l].coefficient = polynomialB[k].coefficient;
            mergedPolynomial[l].degree = polynomialB[k].degree;
            k++;
            l++;
        }

        printf("%d\n", l);
        for (int j = 0; j < l; j++)
        {
            printf("%lld ", mergedPolynomial[j].coefficient);
        }
        putchar('\n');
        for (int j = 0; j < l; j++)
        {
            printf("%d ", mergedPolynomial[j].degree);
        }
        putchar('\n');

        free(polynomialA);
        free(polynomialB);
        free(mergedPolynomial);
    }

    return 0;
}