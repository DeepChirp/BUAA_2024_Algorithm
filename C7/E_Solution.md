# 复习安排题解

## 分析

这道题是经典的活动安排问题。题目给出$k$门课程，每门课程有固定的复习时间区间$[l_i, r_i]$，要求在同一时间段只能复习一门课程，求最多能复习多少门课程。

对于这类问题，我们可以采用贪心策略：按照结束时间从早到晚排序，每次选择结束时间最早且与已选课程不冲突的课程。这样的策略是最优的，因为选择结束时间早的课程能为后续课程留下更多的时间空间。

## 实现思路

1. 将所有课程按照结束时间排序
2. 维护一个时间点`current_index`表示当前已安排到的时间
3. 遍历排序后的课程:
   - 若当前课程开始时间大于`current_index`，则可以选择该课程
   - 选择课程后，将`current_index`更新为当前课程的结束时间

## 复杂度

- 时间复杂度: $O(TKlogK)$，其中$T$是测试组数，$K$是每组数据的课程数
- 空间复杂度: $O(K)$

## 示例代码

```cpp
#include <cstdbool>
#include <cstdint>
#include <iostream>

using namespace std;

struct Activity
{
    uint64_t start;
    uint64_t end;
};

auto cmp(const void *a, const void *b) -> int
{
    struct Activity p_a = *(struct Activity *)a;
    struct Activity p_b = *(struct Activity *)b;
    uint64_t num_a = p_a.end;
    uint64_t num_b = p_b.end;
    if (num_a > num_b)
    {
        return 1;
    }
    if (num_a == num_b)
    {
        return 0;
    }
    return -1;
}

auto main() -> int
{
    uint64_t T;
    cin >> T;
    for (size_t i = 0; i < T; ++i)
    {
        uint64_t n, k;
        cin >> n >> k;
        struct Activity activities[k];
        for (int j = 0; j < k; ++j)
        {
            cin >> activities[j].start >> activities[j].end;
        }
        qsort(activities, k, sizeof(struct Activity), cmp);
        uint64_t current_index = 0;
        uint64_t result = 0;
        for (size_t j = 0; j < k; ++j)
        {
            if (activities[j].start > current_index)
            {
                result++;
                current_index = activities[j].end;
            }
        }
        cout << result << '\n';
    }
}
```

## 说明

本题的关键在于证明贪心策略的正确性。我们可以通过反证法证明：假设存在一个更优的方案没有选择结束时间最早的活动，那么我们总能通过调整，构造出一个选择了结束时间最早的活动且不劣于原方案的新方案，这说明贪心策略是最优的。
