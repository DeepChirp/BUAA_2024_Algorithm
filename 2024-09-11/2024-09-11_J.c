#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int Stack[10000];
    int top = 0;
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("-1\n");
    }
    else
    {
        while (n != 1)
        {
            Stack[top++] = n;
            if ((n + 1) % 4 == 0)
            {
                n = (n - 1) / 2;
            }
            else
            {
                n = (n + 1) / 2;
            }
        }
        printf("1 ");
        for (int i = top - 1; i >= 0; i--)
        {
            printf("%d ", Stack[i]);
        }
    }

    return 0;
}
