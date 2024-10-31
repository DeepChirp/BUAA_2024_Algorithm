# 最长的姓名

时间限制：1000 ms / 空间限制：4096 KB / 难度：3

**本题内存限制为 4096 KB， 仅允许 C 语言提交。**

## 题目描述

`2szox` 看着英文算法点名册陷入了沉思，同学们的名字好长啊，他现在想知道最长的20个名字是哪些。具体来说就是给出很多行字符串，请你找出前20长的字符串，并按照输入顺序输出；**如果第20长的字符串有多个，输出先出现的。**

## 输入格式

多行输入，每行一个字符串 $s$ ；

保证字符串 $s$ 的长度 $len$ 满足 $1\leq len \leq 1000$ ，保证输入的字符串总数 $n$ 满足 $20\leq n\leq 10^5$；

字符串仅包含可见字符。

## 输出格式

**按照输入的顺序**，输出前20个最长的字符串。

## 输入样例

    as
    Ren jiangyi
    Ai chizhujiaodezhujiao
    cbj
    Great-designer
    JJJ
    Lucienlrq
    Shi Shangzuiqiangdexingjierxuanshou
    wqhgg
    Long Juanfeng
    lxy
    ljh
    Guo Lichen
    zymdka
    yuruzan
    Wang Wenhan
    cbd
    Li Nanbing
    SongYou
    Bodan's dog
    casual name
    I don't know

## 输出样例

    Ren jiangyi
    Ai chizhujiaodezhujiao
    cbj
    Great-designer
    JJJ
    Lucienlrq
    Shi Shangzuiqiangdexingjierxuanshou
    wqhgg
    Long Juanfeng
    lxy
    ljh
    Guo Lichen
    zymdka
    yuruzan
    Wang Wenhan
    Li Nanbing
    SongYou
    Bodan's dog
    casual name
    I don't know

## 样例解释

输入共22行字符串，输出样例为前20长的字符串；字符串 `as` 最短不予输出，字符串 `cbd` 虽然和 `cbj` 、 `ljh` 等字符串长度相等，但在输入顺序中它后出现，故不予输出。
