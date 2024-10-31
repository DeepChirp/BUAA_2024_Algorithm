# J题题解

## 题目描述

给定一棵满二叉树的一个节点的编号$(p, q)$，求出其下一个节点的编号。

## 分析

显然可以分为两种情况：

1. 当该节点为该层的最后一个节点时，下一个节点为下一层的第一个节点。
2. 当该节点不是该层的最后一个节点时，下一个节点为同一层的下一个节点。

对于第一种情况，则该节点的$q = 1$，下一个节点的$p = 1$，$q = p + 1$。

对于第二种情况，则两个节点存在至少一个相同的祖先节点，因此可以通过计算两个节点的祖先节点的编号，然后计算出两个节点的编号。

## 代码实现

```c
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
```
