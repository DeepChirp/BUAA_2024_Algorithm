# k-逆序对

时间限制：1000 ms / 空间限制：65536 KB / 难度：6

## 题目描述

给定一个序列 $a_1,a_2,\ldots,a_n$ 和一个正整数 $k$，如果 $1 \le i < j \le n$ 且 $a_i > k \cdot a_j $ 我们就将 $ (i, j) $ 称作一个**逆序 $k$ 倍对**。请你计算序列中逆序 $k$ 倍对的个数。

## 输入格式

第一行两个正整数 $n,k$（$1 \le n \le 10^5$，$1 \le k \le 10$），含义同题目描述。

第二个 $n$ 个正整数 $a_1,a_2,\ldots,a_n$（$1 \le a_i < 2^{31}$），含义同题目描述。

为了提高区分度，对于得分占比 $10\%$ 的测试点，我们保证 $1 \le n \le 100$。

## 输出格式

一行一个非负整数，表示序列中逆序 $k$ 倍对的个数。

## 输入样例

    5 2
    5 4 3 2 1

## 输出样例

    4
