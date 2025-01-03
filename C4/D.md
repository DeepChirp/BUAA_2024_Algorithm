# 2024-切钢条

时间限制：1000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

最近钢条厂的生意很红火，各种英寸的钢条供不应求。现在钢条厂接到一份大的订单，需要将一根钢条切成 $n$ 根钢条，订单中第 $i$（$1 \le i \le n$）根钢条的长度是 $l_i$ 英寸。

钢条厂有一种电锯，每开动一次可以把一根钢条锯成两段，锯出 $n$ 根钢条就需要开动 $n - 1$ 次电锯，但是每次电锯开动都需要电费等加工费用，而且加工费用是需要锯开的钢条长度的两倍，比如要把一段长 $3$ 英寸的钢条锯开，就要收 $6$ 元。

容易发现不同的切割次序会产生不同的费用，钢条厂想知道完成订单付出的加工费用最少是多少。

## 输入格式

第一行一个正整数 $n$（$1 \leq n \leq 2 \times 10^5$），表示订单中需要钢条的个数。

接下来一行 $n$ 个正整数 $l_1,l_2,\ldots,l_n$（$1 \leq l_i \leq 5 \times 10^4$），表示订单中每一根钢条需要的长度。

## 输出格式

一行一个正整数，表示钢条厂付出的最少加工费用。

## 输入样例

    3
    8 5 8

## 输出样例

    68

## 样例解释

根据输入可知需要对总长度为 $8 + 5 + 8  = 21$ 英寸的钢条进行 $2$ 次切割，一种最优的切割方案如下：

1. $21 \Rightarrow 8 + 13$，花费 $42$ 元。

2. $13 \Rightarrow 5 + 8$，花费 $26$ 元。

总花费 $68$ 元，可以证明不存在更优的方案。

## Hint

经典优先队列贪心问题。

优先队列其实本质和堆相似，但是相比于自己手写的堆而言优先队列维护更为方便简单（这也是为什么之前有关堆的题目都会限制 C++），而且将来学习图论也会遇到优先队列优化的 Dijkstra 算法。

C++ 中这些方便编程人员使用的标准模板都已经封装在 STL（标准模板库）中，包括动态变长顺序容器（vector），集合（set），哈希表（unordered_map）等等，感兴趣的同学可以更多了解，在将来的算法学习中 STL 和 `<algorithm>` 函数库将会给同学们提供莫大的的帮助！
