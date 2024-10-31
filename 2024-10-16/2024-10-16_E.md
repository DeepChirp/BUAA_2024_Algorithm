# 方案数 I

时间限制：1000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

「希耶尔·布伦史塔德」正在准备她的太阳系巡回演出。她的仇敌「爱尔奎特·潘德拉贡」会在她的演出过程中偷走钢琴上的黑键。为了让希耶尔的演出顺利进行，她决定准备若干个 $2\times 1$ 的黑键放满 $3\times n$ 的空间中（允许黑键旋转 90° 放置，即每个黑键占据 $2\times 1$ 或 $1\times 2$ 的空间）。现在，希耶尔想知道，她一共有多少种方案？请你输出答案对 $998244353$ 取模的结果。

## 输入

第一行包含一个整数 $t(0\leq t\leq 10^4)$，表示数据组数。

接下来 $t$ 行，每行一个整数 $n(1\leq n\leq 10^5)$.

## 输出

对于每组数据，输出一行，方案数 $998244353$ 取模的结果。

## 输入样例

    3
    2
    3
    4

## 输出样例

    3
    0
    11

## 样例解释

对于 $n=2$ 的情况，共有以下 3 种方案：
$$
\begin{matrix}
\begin{matrix}
\sqsubset\sqsupset\\
\sqsubset\sqsupset\\
\sqsubset\sqsupset\\
\end{matrix}&
\begin{matrix}
\sqsubset\sqsupset\\
\sqcap\sqcap\\
\sqcup\sqcup\\
\end{matrix}&
\begin{matrix}
\sqcap\sqcap\\
\sqcup\sqcup\\
\sqsubset\sqsupset\\
\end{matrix}\end{matrix}$$
