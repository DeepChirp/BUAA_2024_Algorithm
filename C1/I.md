# 莫卡与异或

时间限制：1000 ms / 空间限制：65536 KB / 难度：5

## 题目描述

莫卡想要找出一个序列，这个序列由 $n$ 个互不相同的非负整数组成，且这 $n$ 个非负整数的按位异或值为 $0$。

可以证明，在 $n \ge 3$ 时，至少存在一个满足以上条件的序列。但莫卡不满足于此，她想找出所有满足以上条件的序列中，序列中最大数的最小值。

## 输入格式

第一行一个正整数 $t$（$1 \le t \le 10^4$），表示数据组数。

对于每组数据，一行一个正整数 $n$（$3 \le n \le 10^6$），表示序列的长度。

## 输出格式

对于每组数据，输出一行一个数，代表所有可能序列中，序列中最大数的最小值。

## 输入样例

    2
    3
    4

## 输出样例

    3
    3