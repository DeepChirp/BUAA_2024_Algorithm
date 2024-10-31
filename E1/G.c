#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char arr[1000][1000];

void print(int k, int m, int n, int length);

int main()
{
    int k;
    scanf("%d", &k);

    print(k, (int)pow(3, k) / 2, (int)pow(3, k) / 2, (int)pow(3, k - 1));

    for(int i = 0; i < (int)pow(3, k); i++)
    {
        for(int j = 0; j < (int)pow(3, k); j++)
        {
            putchar(arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void print(int k, int m, int n, int length)
{
    if (k == 0)
    {
        arr[m][n] = '#';
    }
    else
    {
        for (int i = 0; i < length / 2 + 1; i++)
        {
            for (int j = 0; j < length / 2 + 1; j++)
            {
                arr[m - i][n - j] = '.';
                arr[m - i][n + j] = '.';
                arr[m + i][n - j] = '.';
                arr[m + i][n + j] = '.';
            }
        }

        print(k - 1, m - length, n - length, length / 3);
        print(k - 1, m - length, n, length / 3);
        print(k - 1, m - length, n + length, length / 3);
        print(k - 1, m, n - length, length / 3);
        print(k - 1, m, n + length, length / 3);
        print(k - 1, m + length, n - length, length / 3);
        print(k - 1, m + length, n, length / 3);
        print(k - 1, m + length, n + length, length / 3);
    }
}