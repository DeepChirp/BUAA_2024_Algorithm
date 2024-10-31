# B题题解

## 题意

找出一个数组中最大两个数之和。

## 解法

遍历一遍数组，每次判断当前数是否比最大值大，如果是则将最大值赋给第二大值，将当前值赋给最大值，否则判断是否比第二大值大，如果是则将当前值赋给第二大值。最后输出最大值和第二大值之和。

## 代码

```c
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
```
