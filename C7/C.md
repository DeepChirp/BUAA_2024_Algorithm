# 车厢调度

时间限制：1000 ms / 空间限制：65536 KB / 难度：2

## 题目描述

猫猫是火车站调度员！

![猫猫](https://cdn.luogu.com.cn/upload/image_hosting/2mht8kfz.png)

猫猫需要利用一条 `Y` 形轨道调度火车车厢，`Y` 形轨道右侧连接进站轨道，左侧连接出站轨道。

具体来说，火车停靠在进站轨道，共有 $n$ 节车厢，车厢的编号依次是 $1, 2, \dots, n$。最终火车需要停靠在出站轨道，并且车厢编号依次为 $p_1, p_2, \dots, p_n$。

利用 `Y` 形轨道，猫猫每次可以进行以下两种操作之一：

1. 将当前进站轨道最靠近道岔的车厢移入 `Y` 形轨道。
2. 将 `Y` 形轨道最靠近道岔的车厢移入出站轨道。

例如按以下方式，可以将进站轨道停靠的车厢 $1, 2$，变为出站轨道停靠的车厢 $2, 1$。

$$
\scriptsize
\begin{array}{ccc}
\text{出站轨道}~\begin{array}{c|c|c|} \hline \cdots & \phantom{1} & \phantom{1} \\ \hline \end{array}
& &
\begin{array}{|c|c|c} \hline 1 & 2 & \cdots \\ \hline \end{array}~\text{进站轨道} \\
& \diagdown\;\color{red}{\swarrow} & \\
& \color{red}{\downarrow} & \\
& \begin{array}{|c|} \hline \phantom{1} \\ \hline \phantom{1} \\ \hline \vdots \end{array}
\end{array}
\;\xrightarrow{(1)}\;
\begin{array}{ccc}
\text{出站轨道}~\begin{array}{c|c|c|} \hline \cdots & \phantom{1} & \phantom{1} \\ \hline \end{array}
& &
\begin{array}{|c|c|c} \hline 2 & \phantom{2} & \cdots \\ \hline \end{array}~\text{进站轨道} \\
& \diagdown\;\color{red}{\swarrow} & \\
& \color{red}{\downarrow} & \\
& \begin{array}{|c|} \hline 1 \\ \hline \phantom{1} \\ \hline \vdots \end{array}
\end{array}
\;\xrightarrow{(1)}\;
\begin{array}{ccc}
\text{出站轨道}~\begin{array}{c|c|c|} \hline \cdots & \phantom{1} & \phantom{1} \\ \hline \end{array}
& &
\begin{array}{|c|c|c} \hline \phantom{2} & \phantom{2} & \cdots \\ \hline \end{array}~\text{进站轨道} \\
& \color{red}{\nwarrow}\;\diagup & \\
& \color{red}{\uparrow} & \\
& \begin{array}{|c|} \hline 2 \\ \hline 1 \\ \hline \vdots \end{array}
\end{array}
\\~\\
\scriptsize
\;\xrightarrow{(2)}\;
\begin{array}{ccc}
\text{出站轨道}~\begin{array}{c|c|c|} \hline \cdots & \phantom{1} & 2 \\ \hline \end{array}
& &
\begin{array}{|c|c|c} \hline \phantom{2} & \phantom{2} & \cdots \\ \hline \end{array}~\text{进站轨道} \\
& \color{red}{\nwarrow}\;\diagup & \\
& \color{red}{\uparrow} & \\
& \begin{array}{|c|} \hline 1 \\ \hline \phantom{1} \\ \hline \vdots \end{array}
\end{array}
\;\xrightarrow{(2)}\;
\begin{array}{ccc}
\text{出站轨道}~\begin{array}{c|c|c|} \hline \cdots & 2 & 1 \\ \hline \end{array}
& &
\begin{array}{|c|c|c} \hline \phantom{2} & \phantom{2} & \cdots \\ \hline \end{array}~\text{进站轨道} \\
& \diagdown\;\;\diagup & \\
& \vert & \\
& \begin{array}{|c|} \hline \phantom{1} \\ \hline \phantom{1} \\ \hline \vdots \end{array}
\end{array}
$$

猫猫想知道，能否只通过这两种操作将火车按照车厢 $p_1, p_2, \dots, p_n$ 的顺序停靠在出站轨道呢？

## 输入

**本题测试点包含多组数据。**

第一行，一个正整数 $T$（$1\leq T\leq 20$），表示数据组数。

对于每组数据：

第一行，一个正整数 $n$（$1\leq n\leq 10^4$），表示车厢数量。

第二行，$n$ 个互不相同的正整数 $p_1, \dots, p_n$（$1\leq p_i\leq n$），表示目标车厢顺序。

## 输出

对于每组数据：

输出一行，若只通过给出的两种操作能将车厢调度为目标顺序，则输出 `YES`；否则输出 `NO`。

## 输入样例

    3
    2
    2 1
    4
    1 3 2 4
    4
    3 1 2 4

## 输出样例

    YES
    YES
    NO

## 提示

样例中的第一组数据即是题目描述中给出的例子。
