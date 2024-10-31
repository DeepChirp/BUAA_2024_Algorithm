# 2024-导弹轰炸

时间限制：1000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

A 国有 $n$ 个前哨站，每个前哨站有一个重要程度 $w_i$，现在你是 B 国的总指挥，想要使用你们的导弹轰炸 A 国的前哨站。可惜的是 B 国的导弹在轰炸相邻的两个前哨站会产生干扰导致导弹失效。

现在你想知道在导弹互不干扰的情况下，能够轰炸的前哨站的重要程度之和的最大值为多少。

## 输入格式

第一行包含一个整数 $t$ ，表示测试数据的数量，接下来 $t$ 组测试数据。

每组测试数据包含两行。

第一行包含一个正整数 $n(2 \le n \le 10^5)$，含义如上。

第二行包含 $n$ 个正整数 $w_1, w_2, \dots, w_n (1 \le w_i \le 10^5)$，表示每个前哨站的重要程度。

数据保证 $\sum n \le 4 \cdot10^5$ 。

## 输出格式

对于每组测试数据，输出一行一个整数，表示在导弹互不干扰的情况下，能够轰炸的前哨站的重要程度之和的最大值。

## 样例输入

    2
    3
    1 8 2
    4
    10 7 6 14

## 样例输出

    8
    24