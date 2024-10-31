# 爱福若歌·佳木谱斯

时间限制：2000 ms / 空间限制：65536 KB / 难度：3

## 题目描述

小 F 是一只青蛙（*a frog*），小 G 是一只鹅（*a goose*）。

池塘里 $n$ 片荷叶自左向右排成一排，小 F 准备从第 $1$ 片荷叶开始向右跳跃（*jumps*），跳出这 $n$ 片荷叶之后结束。小 G 告诉小 F，如果他跳跃时经过第 $i$ 片荷叶，小 G 就会给小 F $a_i$ 本《算法导论》。当 $a_i < 0$ 时意味着小 F 需要倒给小 G $-a_i$ 本《算法导论》。

小 F 跳跃的方式具体来说是这样的：小 F 可以跳跃很多轮，在一轮中小 F 可以跳跃很多步，一轮中的第 $i$ 步（$i\geq 1$）向右跳跃 $i$ 片荷叶。例如，当小 F 在第 $1$ 片荷叶上时，接下来会跳跃到第 $2, 4, 7, 11, \cdots$ 片荷叶上。小 F 可以在任意荷叶上开启下一轮跳跃，步数重置回第 $1$ 步，但这需要代价——小 F 需要给小 G $w$ 本《算法导论》以重置步数。

小 F 想知道最多能从小 G 处得到多少本《算法导论》。如果小 F 不得不给小 G《算法导论》，那么视为小 F 从小 G 处得到负数本《算法导论》。

注意小 F 不必经过第 $n$ 片荷叶，但是小 F 必须向右跳跃直到跳出这 $n$ 片荷叶。

## 输入

第一行，一个正整数 $T$（$1\leq T\leq 5$），表示数据组数。

对于每组数据：

第一行，两个正整数 $n, w$（$1\leq n\leq 10^5$，$0\leq w\leq 10^9$），表示荷叶数量，以及重置步数的代价。

第二行，$n$ 个整数 $a_1, a_2, \dots, a_n$（$-10^9\leq a_i\leq 10^9$），表示经过每片荷叶时小 G 会给小 F 《算法导论》的数量。

## 输出

对于每组数据：输出一行，一个整数，表示小 F 最多能从小 G 处得到《算法导论》的数量。

## 输入样例

    2
    7 4
    1 -2 3 -1 2 5 2
    7 5
    1 -2 3 -1 2 5 2

## 输出样例

    1
    0