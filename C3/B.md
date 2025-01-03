# 2024-钢管切割

时间限制：1000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

给定一段长度为 $n$ 英寸的钢管和一个价格表，该价格表表示长度为 $i$（$i = 1,2,\ldots,n$）英寸的钢管的价格为 $p_i$。求钢管切割方案，使得总销售价格最大，注意**钢管的长度必须为整英寸**。

## 输入

第一行一个正整数 $n$（$1 \le n \le 10^4$），表示钢管的总长度。

第二行 $n$ 个正整数 $p_1,p_2,\ldots,p_n$（$1 \le p_i \le 10^7$），表示钢管的价格。

## 输出

第一行一个正整数，表示最大总销售价格。

第二行一个正整数 $k$，表示钢管被分割成 $k$ 段。

第三行 $k$ 个正整数 $a_1, \dots, a_k$，表示钢管的分割方式，需保证 $\sum a_i = n$

如果有多种分割方案，输出任意一种即可。

## 输入样例 1

    4
    1 5 8 9

## 输出样例 1

    10
    2
    2 2

## 输入样例 2

    10
    1 5 8 9 10 17 17 20 24 30

## 输出样例 2

    30
    1
    10

## Hint

经典线性动态规划问题，本题的伪代码具体可以参考算法导论 P205 或者课件 PPT。
