#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        unsigned int p, q;
        scanf("%u %u", &p, &q);

        // deal with the special case
        if (q == 1)
        {
            printf("%u %u\n", 1, p + 1);
            continue;
        }

        // find the first left child
        unsigned int n = (p - 1) / q + 1;
        p = (p - 1) % q + 1;

        // find parent
        q -= p;

        // find the right child
        p += q;

        // find the left child
        q += p * (n - 1);

        printf("%u %u\n", p, q);
    }

    return 0;
}