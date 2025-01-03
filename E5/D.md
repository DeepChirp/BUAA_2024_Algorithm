# 2024-Bellalabella 与中位数

时间限制：2000 ms / 空间限制：65536 KB / 难度：4

## 题目描述

Bellalabella 学到了中位数的知识，Bellalabella 想知道对于一个长度为 $n$ 的序列 $a_1,a_2,\ldots,a_n$，所有前缀的中位数是多少。

由于 Bellalabella 学艺不精，不知道长度为偶数的序列的中位数的定义，因此她只需要你求出长度为奇数的所有前缀的中位数。

一个长度为 $2n-1$ 的序列的中位数是将这个序列从小到大排序后第 $n$ 个位置的数，例如 $[1, 3, 2]$ 中位数为 $2$，$[2, 3, 2]$ 中位数为 $2$。

## 输入格式

第一行一个正整数 $t$（$1 \le t \le 10$），表示数据组数。

对于每组数据，第一行一个正奇数 $n$（$1\le n \le 10^5$），含义同题目描述。

第二行 $n$ 个整数 $a_1,a_2,\ldots,a_n$（$0 \le a_i \le 10^5$），含义同题目描述。

对于得分占比 $50\%$ 的测试点，保证 $0 \le a_i \le 20$。

## 输出格式

对于每组数据，输出一行 $\dfrac{n + 1}{2}$ 个整数，第 $i$ 个数表示长度为 $2i - 1$ 的前缀的中位数。

## 输入样例

    2
    5
    3 4 5 1 2
    13
    13 25 19 11 29 19 17 17 5 9 11 11 3

## 输出样例

    3 4 3
    13 19 19 19 17 17 13
