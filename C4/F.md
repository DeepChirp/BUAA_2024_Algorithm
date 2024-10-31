# 直击西溜线

时间限制：1000 ms / 空间限制：65536 KB / 难度：3

## 题目描述

>*「哎呦！刹不住车了嘿！现在人追着车跑嘿！现在人追着车跑。」*
>
>*「这回这车速度可快，人跑着追不上了。□□，已经□下去了。追都追不上了……」*
>
>*——一位北京大爷*

西溜线溜车了！你想光速赶到现场看事故演习。

已知你现在所在的地铁站站名，以及事故演习所在的地铁站站名。请问前往事故演习所在地铁站最少需要换乘多少次？

## 输入

第一行，两个正整数 $n, q$（$1\leq n\leq 25$，$1\leq q\leq 2\times 10^3$），分别表示地铁线路条数，以及询问次数。

接下来描述 $q$ 组询问。对于一组询问：

+ 第一行，一个字符串，表示现在所在的地铁站站名。
+ 第二行，一个字符串，表示事故演习所在的地铁站站名。

接下来描述 $n$ 条地铁线路。对于一条地铁线路：

+ 第一行，一个正整数 $m$，表示站点数量。
+ 接下来 $m$ 行，每行一个字符串，表示该条地铁依次串连地铁站的站名。
+ 地铁线路可以双向乘坐。第一个站名与最后一个站名相同，则表示该条地铁线路是环线。

保证地铁站站名仅包含数字、英文字母、空格、`(`、`)`、`.`、`&`，并且地铁站站名长度不超过 $51$。

同一地铁站站名指代同一地铁站。也就是说包含相同地铁站站名的不同线路，可以在这一地铁站换乘。

保证地铁线网是连通的。保证 $\sum m \leq 489$。

## 输出

对于每组询问，输出一行，一个整数，表示最少需要换乘的次数。

## 输入样例

    2 2
    Xitucheng
    Fragrant Hills
    Fragrant Hills
    Wan'an
    22
    Bagou
    Suzhou Jie
    Haidian Huangzhuang
    Zhichun Li
    Zhichun Lu
    Xitucheng
    Mudanyuan
    Jiande Men
    Beitucheng
    Anzhenmen
    Huixin Xijie Nankou
    Shaoyaoju
    Taiyanggong
    Sanyuanqiao
    Liangma Qiao
    Agricultural Exhibition Center
    Tuanjiehu
    Hujialou
    Jintai Xizhao
    Guomao
    Shuangjing
    Jingsong
    6
    Bagou
    Summer Palace West Gate
    Chapeng
    Wan'an
    China National Botanical Garden
    Fragrant Hills

## 输出样例

    1
    0

## 提示

对于第一组询问，从 `Xitucheng` 前往 `Fragrant Hills` 可以仅在 `Bagou` 换乘一次。

对于第二组询问，从 `Fragrant Hills` 前往 `Wan'an` 仅需乘坐第二条地铁线路，不需要换乘。[（真的是地铁吗？）](https://www.bjsubway.com/subway/images/lwt.png)
