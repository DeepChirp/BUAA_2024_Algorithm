# 2024-排序？数数！

时间限制：1000 ms / 空间限制：65536 KB / 难度：4

## 题目描述

对于一个数组 $A = [a_1, a_2, \cdots, a_n]$，定义
$$
f(A) = \sum_{i = 1}^n \mathrm{order}(a_i) \cdot a_i
$$

其中
$$
\mathrm{order}(a_i) = 1 + \sum_{\substack{a_j < a_i \\\ 1 \leq j \leq n}} 1
$$

现给出一个随机数生成器如下：

    #include <stdio.h>
    #define N 5000005

    int nextRand() {
        static unsigned int rnd_num = 0x80000001;
        static int mod = 1e5 + 3;

        rnd_num ^= rnd_num >> 10;
        rnd_num ^= rnd_num << 9;
        rnd_num ^= rnd_num >> 25;
        return rnd_num % mod;
    }

    int a[N];

    int main() {
        int tt;
        scanf("%d", &tt);
        while (tt--) {
            int n;
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                a[i] = nextRand();
            }
        }
        return 0;
    }

对于每组测试数据，你需要使用上述随机数生成器生成 $n$ 个数 $a_1, a_2, \cdots, a_n$，记 $A = [a_1, a_2, \cdots, a_n]$，你需要求出 $f(A)$ 的值。

**注意**：对于一个测试点有多组测试数据，在每组测试数据之间不需要重置随机数生成器，在后一组测试中，只需要继续调用随机数生成器直接得到随机数即可。

## 输入

第一行一个正整数 $T \ (1 \leq T \leq 10)$ 表示数据组数。

接下来 $T$ 组数据：

一行一个正整数 $n \ (1 \leq n \leq 5 \cdot 10^6)$ 表示数组 $A$ 的长度。

## 输出

对于每组数据，输出一行一个正整数表示 $f(A)$ 的值。

## 输入样例

    3
    11
    101
    1009

## 输出样例

    3832359
    353053098
    34254309646

## 提示

一个数 $a_i$ 的 $\mathrm{order}$ 定义为 **数组内全部元素** 比它小的数的个数加一，例如对于 $A = [1, 1, 2, 3, 3, 3, 4]$ 有：
$$
\mathrm{order}(1) = 1, \  \mathrm{order}(2) = 3, \  \mathrm{order}(3) = 4, \  \mathrm{order}(4) = 7
$$

因此
$$
f(A) = 1 \cdot 1 + 1 \cdot 1 + 3 \cdot 2 + 4 \cdot 3 + 4 \cdot 3 + 4 \cdot 3 + 7 \cdot 4 = 72
$$

另外，提醒大家多多注意代码中 $\text{mod}$ 的范围。
