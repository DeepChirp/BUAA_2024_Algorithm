# 2024-Jump

时间限制：1000 ms / 空间限制：65536 KB / 难度：5

## 题目描述

*I just wanna jump, jump, jump, jump, jump, jump, jump, jump, jump, jump, jump, jump, jump, jump*
*I just wanna jump, jump, jump, jump, jump, jump, jump, jump*
*Red lights, blue lights, bright lights*
*I just wanna jump, jump, jump, jump!*

给定一个仅由 `U`, `D`, `L`, `R` 构成的字符串 $S$，并记 $S^\infty = S + S + \cdots$，其中 $+$ 表示字符串的连接。

初始时你位于 $(0, 0)$。$S^\infty$ 的每一个字符 $S^\infty_i$ 均对应一次移动：

+ $S^\infty_i = \mathtt{U}$，则你向上移动 $1$ 单位长度，也即 $(x,y)\to (x,y+1)$；
+ $S^\infty_i = \mathtt{D}$，则你向下移动 $1$ 单位长度，也即 $(x,y)\to (x,y-1)$；
+ $S^\infty_i = \mathtt{L}$，则你向左移动 $1$ 单位长度，也即 $(x,y)\to (x-1,y)$；
+ $S^\infty_i = \mathtt{R}$，则你向右移动 $1$ 单位长度，也即 $(x,y)\to (x+1,y)$。

你将以从左往右的顺序依照 $S^\infty$ 的每个字符依次移动。给定整数 $p, q$，试求出你**第一次**到达 $(p,q)$ 时的移动次数。特殊地，若无论如何都无法到达 $(p,q)$，则输出 $-1$。

## 输入

**本题测试点包含多组数据。**

第一行，一个正整数 $T$（$1\leq T\leq 5000$），表示数据组数。

对于每组数据：

第一行，一个正整数 $|S|$（$1\leq |S|\leq 100$），表示字符串 $S$ 的长度。

第二行，两个正整数 $p, q$（$-10^9\leq p, q\leq 10^9$）。

第三行，一个仅包含 `U`, `D`, `L`, `R` 的字符串 $S$。

## 输出

对于每组数据，输出一行，一个整数，表示第一次到达 $(p,q)$ 时的移动次数。若无法到达 $(p,q)$ 则输出 $-1$。

## 输入样例

    4
    5
    -1 -6
    LRUDD
    3
    0 0
    UUR
    2
    -1 -1
    RD
    12
    -1000000000 -1000000000
    ULLLLUDRRRDD

## 输出样例

    31
    0
    -1
    12000000000
