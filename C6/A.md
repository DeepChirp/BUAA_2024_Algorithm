# 2024-克鲁斯卡尔与普莱姆

时间限制：1000 ms / 空间限制：65536 KB / 难度：4

## 题目描述

克鲁斯卡尔有一个图

而普莱姆想要一个树

克鲁斯卡尔说他可以从图中挖出一个树

但普莱姆更喜欢边权和更小的树

克鲁斯卡尔小心翼翼的挖出了一棵树

但普莱姆却说那不是最小的。

克鲁斯卡尔懵了

最小的树究竟是有多小呢？

## 输入

输入一个带权图：

第一行两个正整数 $n, m$ 表示图中的点数和边数。

接下来的 $m$ 行，每行三个正整数 $u, v, w$，表示一条连接 $u, v$ 且权值为 $w$ 的边

## 输出

输出一行一个正整数，表示最小生成树的边权。

## 输入样例

    3 3
    1 2 1
    1 3 2
    2 3 1

## 输出样例

    2

## 样例解释

克鲁斯卡尔有一个好听的英文名：Kruskal

不过克鲁斯卡尔更喜欢普莱姆的：Prim

（最小生成树，选两条权值为 1 的边）

## 数据范围

$1\leq n\leq 2000$

$1\leq m\leq 5000$

$1\leq u, v \leq n$

$1\leq w\leq 10000$
