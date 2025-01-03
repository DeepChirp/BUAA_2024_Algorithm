# 2024-OBST？OBST！

时间限制：1000 ms / 空间限制：65536 KB / 难度：3

## 题目描述

对于集合 $\\{1,2,\ldots,n\\}$ 的一棵二叉搜索树，定义一个节点的深度为该节点到根节点的距离，设权值为 $i$ 的点深度为 $d_i$，给定序列 $p_1,p_2,\ldots,p_n$，定义该二叉搜索树的**代价和**为：

$$
\sum_{i=1}^n(d_i+1)p_i
$$

请你求解集合 $\\{1,2,\ldots,n\\}$ 所有二叉搜索树中最小的代价和，并输出任意一种最小代价的二叉搜索树结构。

## 输入格式

第一行两个正整数 $n$（$1 \leq n \leq 500$），含义同题目描述。

第二行 $n$  个正整数 $p_1,p_2,\ldots,p_n$（$1 \le p_i \le 10^4$），含义同题目描述。

## 输出格式

第一行一个正整数，表示最小的代价和。

接下共 $n$ 行，每行两个整数，分别表示点 $i$ 的左儿子节点与右儿子节点，如果点 $i$ 无左/右儿子节点，则对应位置输出 $-1$。

如果有多种符合题目的答案，输出任意一种即可。

## 输入样例

    5
    15 10 5 10 20

## 输出样例

    130
    -1 -1
    1 5
    -1 -1
    3 -1
    4 -1

## 样例解释

代价和为 $10 \times 1 + (15+20)  \times 2 + 10  \times 3 + 5 \times 4 = 130$。

## Hint

经典区间动态规划问题，所有伪代码可以参考算法导论 226-230 页 ，**需要注意题目定义的不同之处**。
