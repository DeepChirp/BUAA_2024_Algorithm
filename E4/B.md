# 2024-妮妮的约会大作战

时间限制：1000 ms / 空间限制：65536 KB / 难度：4

## 题目描述

妮妮的社团正在举办联谊活动！目前报名的有 $n$ 个男生和 $n$ 个女生。其中第 $i$ 个男生魅力值为 $a_i$，只喜欢魅力值不小于 $p_i$ 的女生；第 $i$ 个女生魅力值为 $b_i$，只喜欢魅力值不小于 $q_i$ 的男生。

男生与女生能约会当且仅当两人相互喜欢。妮妮希望让尽可能多的人能约会成功，那么最多有多少对情侣能约会成功呢？

## 输入格式

第一行一个正整数 $n$（$1 \le n \le 400$），表示男生和女生的数量。

第二行 $n$ 个非负整数 $a_1, a_2, \dots , a_n$（$0 \le a_i \le 10^9$），表示男生的魅力值。

第三行 $n$ 个非负整数 $p_1, p_2, \dots , p_n$（$0 \le p_i \le 10^9$），表示男生喜欢的女生魅力值最小值。

第四行 $n$ 个非负整数 $b_1, b_2, \dots , b_n$（$0 \le b_i \le 10^9$），表示女生的魅力值。

第五行 $n$ 个非负整数 $q_1, q_2, \dots , q_n$（$0 \le q_i \le 10^9$），表示女生喜欢的男生魅力值最小值。

## 输出格式

一行一个非负整数，表示最多能有几对情侣约会成功。

## 输入样例

    5
    3 10 2 1 5
    9 7 2 10 1
    1 6 10 8 0
    9 4 4 1 8

## 输出样例

    3