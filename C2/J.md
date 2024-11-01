# 2024-三叉卡特兰数

时间限制：1000 ms / 空间限制：65536 KB / 难度：5

## 题目描述

你肯定见过卡特兰数的一种递推公式了，它具有如下形式：
$$
C_n = C_0C_{n - 1} + C_1C_{n - 2} + \cdots + C_{n - 1}C_0 =  \sum_{i = 0}^{n - 1} C_i C_{n - 1 - i}
$$

有一天你唱歌的时候突然想到，能不能对卡特兰数做一些推广呢，于是你一拍脑子想到了一个「三叉卡特兰数」，它的递推公式具有如下形式：
$$
C_n = \sum_{\substack{i + j + k = n - 1 \\\ i, j, k \geq 0}} C_iC_jC_k
$$

现在定义 $C_0 = 1$，请你求出「三叉卡特兰数」的第 $n$ 项 $C_n$。由于答案可能很大，请你将 $C_n$ 对 $998244353$ 取模后输出。

## 输入

第一行一个正整数 $T \ (1 \leq T \leq 5000)$ 表示数据组数。

接下来 $T$ 组数据：

一行一个非负整数 $n \ (0 \leq n \leq 5000)$。

## 输出

对于每组数据，输出一行一个正整数 $C_n$ 表示第 $n$ 项「三叉卡特兰数」。

## 输入样例

    6
    1
    2
    4
    8
    16
    32

## 输出样例

    1
    3
    55
    43263
    448138955
    507624406

## 部分

前 40% 数据有  $1 \leq T \leq 100, 0 \leq n \leq 100$。

前 60% 数据有  $1 \leq T \leq 5000, 0 \leq n \leq 500$。

100% 数据有  $1 \leq T \leq 5000, 0 \leq n \leq 5000$。
