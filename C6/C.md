# 2024-线性袋鼠

时间限制：2000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

小 A 正在学习「线性袋鼠」，他在解题过程中写出了下面这个式子：

$$
\begin{pmatrix}
1 & 1 & 1 & \cdots & 1 \\
1 & \omega & \omega^2 & \cdots & \omega^{n - 1} \\
1 & \omega^2 & \omega^4 & \cdots & \omega^{2(n - 1)} \\
 & & \vdots & & \\
1 & \omega^{n - 1} & \omega^{2(n - 1)} & \cdots & \omega^{(n - 1)^2} \\
\end{pmatrix} \cdot \begin{pmatrix}
a_1 \\
a_2 \\
a_3 \\
\vdots \\
a_n
\end{pmatrix} =  \begin{pmatrix}
c_1 \\
c_2 \\
c_3 \\
\vdots \\
c_n
\end{pmatrix}
$$

他在解这道题的过程中保证了式中的 $n = 2^k$ 且  $\omega = \cos\frac{2\pi}{n} + \mathrm{i} \sin\frac{2\pi}{n}$。

现在小 A 已经知道这个式子中 $c_1, c_2, \cdots, c_n$ 的值，但他不知道该如何求出 $a_1, a_2, \cdots, a_n$，你能帮帮他吗？

## 输入

第一行一个正整数 $k \ (1 \leq k \leq 18)$，表示式中的 $n = 2^k$。

第二行 $n$ 个整数表示式中的 $c_1, c_2, \cdots, c_n \ (0 \leq |c_i| \leq 100)$。

## 输出

输出 $n$ 行，每行两个实数，表示 $a_i \  (1 \leq i \leq n)$ 的实部和虚部，结果保留两位小数。注意在对接近 $0$ 的负数四舍五入时应输出 `0.00` 而非 `-0.00`。

## 输入样例

    3
    -93 -20 -89 93 -81 -4 -5 -71

## 输出样例

    -33.75 0.00
    -17.41 -2.58
    -10.00 5.75
    14.41 -23.58
    -33.25 0.00
    14.41 23.58
    -10.00 -5.75
    -17.41 2.58
