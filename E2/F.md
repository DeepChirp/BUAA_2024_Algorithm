# Maze No.9

时间限制：1000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

小 A 发现他掉进了 $n$ 行 $m$ 列格子形成的迷宫里！

这 $n\times m$ 个格子中，每个格子为障碍物或空地。小 A 只能在空地上移动，一次移动时先选定方向，并在该方向上一直前进，直到前方的格子是障碍物，或是抵达迷宫边界，或是抵达迷宫出口。也就是说，一次移动不一定只移动到相邻的格子。

小 A 知道他现在位于第 $x_s$ 行第 $y_s$ 列的格子，迷宫出口位于第 $x_t$ 行第 $y_t$ 列的格子。小 A 想知道他到迷宫出口所需的最少移动次数。如果小 A 无法抵达迷宫出口，那么输出 $-1$。

## 输入

第一行，一个正整数 $T$（$1\leq T\leq 10$），表示数据组数。

对于每组数据：

第一行，两个正整数 $n, m$（$1\leq n \times m\leq 10^5$），表示迷宫大小。

第二行，四个正整数 $x_s, y_s, x_t, y_t$（$1\leq x_s, x_t\leq n$，$1\leq y_s, y_t\leq m$），表示当前位置和出口位置。

接下来 $n$ 行，每行一个长度为 $m$ 的仅包含 `.` 和 `#` 的字符串，表示各个格子的种类。其中 `.` 表示空地，`#` 表示障碍物。

保证当前位置和出口位置均不为障碍物。

## 输出

对于每组数据：输出一行，一个整数，表示答案。

## 输入样例

    2
    3 4
    3 1 1 2
    #..#
    ....
    .#..
    3 4
    3 1 1 2
    ...#
    ....
    .#..

## 输出样例

    6
    2
