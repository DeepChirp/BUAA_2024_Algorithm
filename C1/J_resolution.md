# 魔法糖果题解

## 分析

由于初始的糖果数量为`1`，由题目容易知道，糖果数始终是奇数，不会是偶数。因此若糖果数为偶数，则不存在满足题意的方法。

若糖果数为奇数且大于1，设其为$k$，上一个数字为$k_0$，那么$k = 2 k_0 + 1$或$k = 2 k_0 - 1$，即$k_0 = \frac{k}{2} \pm \frac{1}{2}$。由于$k$为奇数，因此总可以找到一个符合题意的奇数$k_0$，且$k_0 < k$。如此循环，则最终可使$k_0 = 1$。因此我们只需要根据此方案，不断寻找为奇数的原数$k_0$，即可满足题意。

上述的过程为倒序。因此在计算过程中，我们可以使用栈保存中间计算的所有数字。当计算结果为`1`时，再依次输出栈中的所有数字即可。

## 示例代码

```c
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
```