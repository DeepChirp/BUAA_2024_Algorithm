# 寄蒜几盒IX

时间限制：3000 ms / 空间限制：131072 KB / 难度：6

## 题目描述

小 A 想给小 B 寄几盒蒜。

$\mathbb{R}^2$ 平面上有 $n$ 家邮局，这些邮局依次标号 $1, 2, \dots, n$。第 $i$ 家邮局的坐标为 $(x_i, y_i)$。

小 A 从第 $i$ 家邮局向第 $j$（$i\neq j$）家邮局寄蒜需要花费 $\displaystyle {x_ix_j \cdot y_iy_j \over i-j}$。负数意味着小 A 可以从邮局拿到邮费……有些奇怪，或许这就是 $\mathbb{R}^2$ 平面的规定吧。

由于小 A 忘了问小 B 的地址，当小 A 选择从第 $i$ 家邮局寄出时，小 A 会**等概率**选择其余 $n-1$ 家邮局之一作为目的地。

小 A 想比较从每家邮局寄出的期望花费，于是小 A 找到了你帮忙计算。形式化地说，你需要对于每个 $1\leq i\leq n$ 计算：
$$
\mathrm{E}_i = {1\over n - 1} \sum_{\substack{1\leq j\leq n \\ j\neq i}} {x_ix_j \cdot y_iy_j \over i-j}
$$

## 输入

**本题测试点包含多组数据。**

第一行，一个正整数 $T$（$1\leq T\leq 5$），表示数据组数。

对于每组数据：

第一行，一个正整数 $n$（$2\leq n\leq 10^5$），表示平面上邮局的数量。

接下来 $n$ 行，每行两个正整数 $x_i, y_i$（$-50\leq x_i\leq 50$，$-50\leq y_i\leq 50$），表示第 $i$ 家邮局的坐标。

## 输出

对于每组数据：

一行，$n$ 个实数，表示 $\mathrm{E}_1, \mathrm{E}_2, \dots, \mathrm{E}_n$。答案保留三位小数，注意在对接近 $0$ 的负数四舍五入时应输出 `0.000` 而非 `-0.000`。

## 输入样例

    1
    3
    2 -1
    -3 2
    5 3

## 输出样例

    1.500 51.000 -52.500
