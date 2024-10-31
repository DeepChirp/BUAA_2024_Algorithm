# 排位胜率（Easy Version）

时间限制：2000 ms / 空间限制：65536 KB / 难度：1

## 题目描述

**这是问题的简单版本，与困难版本仅在 $n$ 的限制与输出要求不同**

某人在玩一款三字游戏的排位赛时，发现策划为了防止玩家输太多退游，设置了如下保护机制：

- 每连输 $n$ 局后，会匹配到人机，人机技术很菜，即使玩家打的再菜，系统也会通过一些微妙的操作保证玩家胜利。

现在某人想知道，在自己正常对战的胜率为 $p\%$ 的基础上，结合此保护政策，自己玩无穷局的胜率。由于游戏界面不可能展示太多位小数，你只需要求出来保留三位小数的结果。

## 输入

输入共一行两个正整数 $n,p$ ($1\le n\le 50, 1\le p\le 99$）。

## 输出

对于每组数据，输出一行一个三位小数代表胜率

## 输入样例

    1 50

## 输出样例

    0.667