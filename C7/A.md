# 2024 - 选择题 III

时间限制：1000 ms / 空间限制：65536 KB / 难度：1

## 选择题作答要求

请根据题目要求完成下列**不定项**选择题，并将答案以每行一个**只包含大写英文字母的、字母按照升序的字符串**的格式输出，不要输出多余空格。假设有 $n$ 道题目，那么 Special Judge 只会读取你输出的前 $n$ 行内容，如果输出**不足** $n$ 行也会被判定为格式错误。
例如，有四道选择题，第一题答案为 `ABCD`，第二题答案为 `ABCD`，第三题答案为 `ABCD`，第四题答案为 `ABCD`，你应该输出以下答案。

    ABCD
    ABCD
    ABCD
    ABCD

你可以使用如下的代码进行输出：

    #include <stdio.h>

    int main(){
        puts("ABCD");
        puts("ABCD");
        puts("ABCD");
        puts("ABCD");
    }

只要满足上述格式要求，即返回 `Accepted` 结果，不返回真实评测结果，待比赛结束后正式评测使用每个人的最后一次 `Accepted` 的提交记录进行正式评测。

如果格式错误，会返回 `Presentation Error` 结果。

每道题得分占比相同，**少选和错选均不得分**。

## 题目描述

### 第1题

KMP算法的提出者是哪几位___。

- A. D.E.Knuth
- B J.H.Morris
- C V.R.Pratt
- D htunK.E.D
- E sirroM.H.J
- F ttarP.R.V

### 第2题

n个节点 (1,...,n) 的BST的不同形态数满足___。

- A. $\Omega (\frac{4^n}{n^\frac{3}{2}})$
- B. $O(\frac{4^n}{n^\frac{3}{2}})$
- C. $\omega (1)$
- D.  $o(4^n)$

### 第3题

以下说法正确的是___。

- A. 均摊分析主要包括聚合分析、记账分析和势能分析。
- B. 均摊分析考虑的是最好情况下的平均时间
- C. 期末考试可以使用共享文档
- D. 使用聚合分析能够分析出Graham's Scan算法的复杂度是$O(nh)$

### 第4题

以下说法正确的是___。

- A. Graham's Scan的时间复杂度是 $O(n\lg n)$
- B. Jarvis's March的时间复杂度是 $O(n\lg n)$
- C. Prim算法是贪心思想的应用
- D. 对于网络流图上的容量 $c$ 和流量 $f$ ,有 $0\leq c(u,v) \leq f(u,v)$.

### 第5题

对于含有负权边但不含负环的图，以下哪些算法能求出正确的最短路？___。

- A. Floyd
- B. Dijkstra
- C. Bellman Ford
- D. 以上都不对
