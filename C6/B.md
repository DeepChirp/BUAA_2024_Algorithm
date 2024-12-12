# 位逆序置换

时间限制：1000 ms / 空间限制：65536 KB / 难度：1

## 题目描述

*本题旨在引导同学们关注并尝试理解 FFT 非递归写法中的位逆序置换方法。数据范围宽松，同学们可以根据自己的理解进行多样化的实现.*

给定一个长度为 $n$ （$n$ 为 $2$ 的幂次）的数组 $a$，下标从 $0$ 到 $n-1$。请输出数组 $a$ 经过位逆序置换后的结果。

假设 $n = 2^k$，位逆序置换具体如下：

+ 对于 $0 < i < n - 1$，将 $i$ 写成 $k$ 位二进制数，并将二进制数各个数位逆序排列（也就是倒过来，例如 $(011)_2\to(110)_2$），得到新的 $k$ 位二进制数，记作 $\text{rev}(i)$；
+ 假设置换后的数组是 $a'$，那么 $a'_i$ 取 $a_{\text{rev}(i)}$ 的值。

例如，对于 $n=8$，有：

|$i$|$0=(000)_2$|$1=(001)_2$|$2=(010)_2$|$3=(011)_2$|$4=(100)_2$|$5=(101)_2$|$6=(110)_2$|$7=(111)_2$|
|::|::|::|::|::|::|::|::|::|
|$\text{rev}(i)$|$(000)_2=0$|$(100)_2=4$|$(010)_2=2$|$(110)_2=6$|$(001)_2=1$|$(101)_2=5$|$(011)_2=3$|$(111)_2=7$|

因此置换相当于交换 $a_1$ 与 $a_4$，交换 $a_3$ 与 $a_6$。

## 输入

第一行一个整数 $n$，保证 $n=2^k$ 且 $n\leq 1024$。

第二行 $n$ 个整数依次表示 $a_0,a_1,a_2\dots a_{n-1}$（$0\leq a_i\leq 3000$）。

## 输出

输出一行 $n$ 个整数，表示数组 $a$ 进行置换操作后的结果。

## 输入样例

    8
    0 1 2 3 4 5 6 7

## 输出样例

    0 4 2 6 1 5 3 7