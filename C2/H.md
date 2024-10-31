# 莫卡的龙

时间限制：3000 ms / 空间限制：65536 KB / 难度：3

## 题目描述

莫卡使用召唤魔法召唤了一条龙，这条龙由编号从 $1$ 到 $n$ 的 $n$ 部分组成，其中第 $1$ 部分为头部。莫卡为了提升自己的魔法熟练度，决定在二维平面上控制这条龙。

最初，第 $i$ 部分的初始位置为 ($i,0$)，之后莫卡会使用 $Q$ 次魔法，每次莫卡会从以下两种魔法中选择一种使用：

- 移动魔法，将龙的头部沿方向 $C$ 移动一个单位，$C$ 是 $R$、$L$、$U$ 和 $D$ 之一，分别代表正 $x$ 方向、负 $x$ 方向、正 $y$ 方向和负 $y$ 方向。除头部之外的每个部分都会跟随其前方的部分移动，即移动后的第 $i$（$2\le i\le n$）部分的位置为移动前第 $i-1$ 部分的位置。龙的任意部分可以彼此重合。
- 查询魔法，莫卡使用该魔法查询第 $q$ 部分的坐标。

莫卡想知道每次使用查询魔法的结果。

## 输入

第一行包含两个正整数 $N,Q$（$2\le N\le 10^6,1\le Q\le 2\times 10^5$），含义如题面所示。

之后 $Q$ 行，每行代表一种魔法，输入形式为如下两种的任意一种：

- $1$ $C$，代表移动魔法，将龙的头部沿方向 $C$ 移动一个单位，$C$ 是 $R$、$L$、$U$ 和 $D$ 中的一种。
- $2$ $q$，代表查询魔法，查询第 $q$ 部分的坐标。

## 输出

对于每个查询魔法，输出一行包含两个整数，代表第 $q$ 部分的坐标。

## 输入样例

    5 9
    2 3
    1 U
    2 3
    1 R
    1 D
    2 3
    1 L
    2 1
    2 5

## 输出样例

    3 0
    2 0
    1 1
    1 0
    1 0

## 样例解释

初始情况下，从 $1$ 到 $5$ 每部分坐标依次为 ($1,0$)，($2,0$)，($3,0$)，($4,0$)，($5,0$)。

第一次移动后，从 $1$ 到 $5$ 每部分坐标依次为 ($1,1$)，($1,0$)，($2,0$)，($3,0$)，($4,0$)。

第二次移动后，从 $1$ 到 $5$ 每部分坐标依次为 ($2,1$)，($1,1$)，($1,0$)，($2,0$)，($3,0$)。

第三次移动后，从 $1$ 到 $5$ 每部分坐标依次为 ($2,0$)，($2,1$)，($1,1$)，($1,0$)，($2,0$)。

第四次移动后，从 $1$ 到 $5$ 每部分坐标依次为 ($1,0$)，($2,0$)，($2,1$)，($1,1$)，($1,0$)。