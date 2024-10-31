#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        char A[2005];
        char B[2005];
        char result[4010];
        memset(result, '0', sizeof(result));
        result[4009] = '\0';

        scanf("%s", A);
        scanf("%s", B);
        int carry = 0;
        int lenA = strlen(A);
        int lenB = strlen(B);

        // multiply A and B
        for (int j = lenA - 1; j >= 0; j--)
        {
            for (int k = lenB - 1; k >= 0; k--)
            {
                int temp = (A[j] - '0') * (B[k] - '0') + carry + (result[lenA + lenB - 2 - j - k] - '0');
                result[lenA + lenB - 2 - j - k] = temp % 10 + '0';
                carry = temp / 10;
            }
            result[lenA + lenB - 1 - j] = carry + '0';
            carry = 0;
        }

        // print
        int lenResult = lenA + lenB;
        while (lenResult > 1 && result[lenResult - 1] == '0')
        {
            lenResult--;
        }
        for (int j = lenResult - 1; j >= 0; j--)
        {
            printf("%c", result[j]);
        }
        printf("\n");
    }

    return 0;
}