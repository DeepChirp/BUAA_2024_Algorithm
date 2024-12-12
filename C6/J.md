# Oshama Scramble

时间限制：1000 ms / 空间限制：65536 KB / 难度：3

## 题目描述

||||||||||||||||||||||||||
|::|
|||||||||||||![](https://arcwiki.mcd.blue/images/f/f4/Songs_oshamascramble.jpg)|||||||||||||
||||||||||||||||||||||||||

**【来自 Shama & Milk 的提示】**若递归深度过深在 OJ 上 RE，可以加入以下代码解决：

    #include <sys/resource.h>
    int main()
    {
        struct rlimit r;
        getrlimit(RLIMIT_STACK, &r);
        r.rlim_cur = 1 << 24;
        setrlimit(RLIMIT_STACK, &r);
        /*
            Your code here.
        */
        return 0;
    }

**该代码仅对 Linux 系统（OJ 评测机）有效。**该代码在 Windows 系统下会导致编译错误，如果你确信其他部分的代码是正确的，可以无视本地的编译错误直接将代码提交到 OJ。

---

给定一张有 $n$ 个顶点与 $m$ 条边的无向图。顶点以 $1, 2, \dots, n$ 标号，每条边的边权均为 $1$。

对于一条路径 $P: p_0 \to p_1 \to p_2 \to \dots \to p_k$，记路径中第 $i$ 条边 $p_{i-1} \to p_i$ 的边权为 $w_i$，定义路径的带权长度为：
$$
L(P) = \sum_{i=1}^k (-1)^{i-1} w_i
$$

定义 $u, v$ 两点间的带权距离为，所有 $u$ 到 $v$ 的路径中最小的带权路径长度，也即：
$$
D(u, v) = \min_{P: u \to \dots \to v} L(P)
$$
特殊地，如果 $u, v$ 之间不连通，定义 $D(u, v) = 0$。

求所有点对之间带权距离之和，也即求下式的值：
$$
\sum_{i=1}^n \sum_{j=1}^n D(i, j)
$$

## 输入

第一行，两个正整数 $n, m$（$1\leq n\leq 2\times 10^5$，$1\leq m\leq 2\times 10^5$），分别表示顶点数与边数。

接下来 $m$ 行，每行两个正整数 $u_i, v_i$（$1\leq u_i, v_i \leq n$），表示图中一条连接结点 $u_i$ 与结点 $v_i$ 的无向边。

## 输出

一行，一个整数，表示答案。

## 输入样例

    3 3
    1 2
    2 3
    3 2

## 输出样例

    4

## 提示

对于样例，计算得到的 $D(u,v)$ 如下表所示：

$$
\begin{array}{|c|ccc|}
\hline
{}_v{}\backslash^u & 1 & 2 & 3 \\
\hline
1 & 0 & 1 & 0 \\
2 & 1 & 0 & 1 \\
3 & 0 & 1 & 0 \\
\hline
\end{array}
$$
