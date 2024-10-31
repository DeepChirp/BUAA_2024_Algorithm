// https://oi-wiki.org/ds/monotonous-stack/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 300005

int n;
int heights[MAXN];
int leftVisible[MAXN];
int rightVisible[MAXN];

int fast_read();

int main()
{
    int T = fast_read();
    while (T--)
    {
        n = fast_read();
        for (int i = 0; i < n; i++)
        {
            heights[i] = fast_read();
        }

        // left
        int stack[MAXN], top = -1;
        for (int i = 0; i < n; i++)
        {
            while (top >= 0 && heights[stack[top]] <= heights[i])
            {
                top--;
            }
            leftVisible[i] = (top == -1) ? i : (i - stack[top] - 1);
            stack[++top] = i;
        }

        // right
        top = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            while (top >= 0 && heights[stack[top]] <= heights[i])
            {
                top--;
            }
            rightVisible[i] = (top == -1) ? (n - i - 1) : (stack[top] - i - 1);
            stack[++top] = i;
        }

        long long totalVisible = 0;
        for (int i = 0; i < n; i++)
        {
            totalVisible += leftVisible[i] + rightVisible[i];
        }

        printf("%lld\n", totalVisible);
    }
    return 0;
}

int fast_read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}
