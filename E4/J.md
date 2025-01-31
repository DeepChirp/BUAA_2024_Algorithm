# 2024-lastendconductor

时间限制：5000 ms / 空间限制：65536 KB / 难度：10

## 题目描述

定义一个字符串 $T$ 是**周期的**，当且仅当存在字符串 $T'$ 使得 $T$ 可由**至少 $2$ 个** $T'$ 依次连接得到。

例如：

+ $T_1=$`gamegame` 是周期的，因为 $T_1=$`gamegame` 可由 $2$ 个 $T_1'=$`game` 连接得到；
+ $T_2=$`qwqqwqqwq` 也是周期的，因为 $T_2=$`qwqqwqqwq` 可由 $3$ 个 $T_2'=$`qwq` 连接得到；
+ $T_3=$`lastendconductor` 不是周期的，因为不存在满足上述条件的 $T_3'$。

对于字符串 $T = T_1T_2\cdots T_{|T|}$，我们称 $T'$ 是 $T$ 的**子序列**，当且仅当存在下标数列 $1\leq p_1 < p_2 < \cdots < p_{|T'|} \leq |T|$ 使得 $T' = T_{p_1}T_{p_2}\cdots T_{p_{|T'|}}$。

给定仅包含小写英文字母的字符串 $S$，请计算 $S$ 的所有**子序列**中周期字符串的最长长度。如果 $S$ 的子序列中不存在周期字符串，则认为答案为 $0$。

## 输入

**本题测试点包含多组测试数据。**

第一行，一个正整数 $T$（$1\leq T\leq 4$），表示数据组数。

对于每组数据：

一行，一个仅包含小写英文字母的字符串 $S$（$1\leq |S|\leq 80$），表示给定的字符串。

## 输出

对于每组数据：

输出一行，一个整数，表示 $S$ 的所有子序列中周期字符串的最长长度。如果 $S$ 的子序列中不存在周期字符串，则输出 $0$。

## 输入样例

    1
    lastendconductor

## 输出样例

    8

## 提示

`lastendconductor` 的所有子序列中最长的周期字符串为 `ndcondco`。
