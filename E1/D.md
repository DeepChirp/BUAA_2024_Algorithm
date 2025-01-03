# 莫卡和序列

时间限制：1000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

莫卡有一个由 $n$ 个正整数组成的序列 $a$ 。莫卡认为序列 $a$ 是**美丽的**当且仅当存在两个数字 $i$ 和 $j$ ($1 \leq i,j \leq n$, $i \neq j$)，使得对于所有的 $k$ ($1 \leq k \leq n$)，$a_k$ 都能被 $a_i$ 或 $a_j$ 整除。

请你判断序列数组 $a$ 是否美丽。

## 输入

每组数据包含多个测试用例。
第一行包含一个正整数 $t$（$1 \leq t \leq 500$），表示测试用例的数量。接下来是每个测试用例的描述。

每个测试用例的第一行包含一个整数 $n$ （$3 \leq n \leq 10^5$），表示序列 $a$ 的长度。

每个测试用例的第二行包含 $n$ 个整数 $a_1,a_2,\ldots,a_n$ （$1 \leq a_i \leq 10^9$），表示数组 $a$ 的元素。

保证所有测试用例中 $n$ 的总和不超过 $10^5$。

## 输出

对于每个测试用例，如果序列 $a$ 是美丽的，输出 "Yes"；否则，输出 "No"（注意大小写）。

## 输入样例

    4
    3
    7 3 8
    5
    7 1 9 3 5
    5
    4 12 2 6 3
    5
    7 49 9 3 1000000000

## 输出样例

    No
    Yes
    Yes
    No
