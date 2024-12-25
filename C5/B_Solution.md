# 题解：寄蒜几盒 I

## 问题分析

给定点 $A$ 和线段 $PQ$，要求计算点 $A$ 到线段 $PQ$ 的最小距离。

根据计算几何，点到线段的最小距离可分为以下几种情况：

1. **投影点在线段上**：计算点 $A$ 在直线 $PQ$ 上的投影点，如果投影点在线段 $PQ$ 上，最小距离为点 $A$ 到投影点的距离。

2. **投影点不在线段上**：最小距离为点 $A$ 到线段两个端点 $P$、$Q$ 中距离较小的一个。

## 解题思路

1. 计算向量 $\vec{PA} = A - P$ 和向量 $\vec{PQ} = Q - P$。

2. 计算参数 $t$，表示点 $A$ 在直线 $PQ$ 上的投影：

   $$
   t = \frac{\vec{PA} \cdot \vec{PQ}}{|\vec{PQ}|^2}
   $$

3. 判断 $t$ 的范围：

   - 当 $0 \leq t \leq 1$ 时，投影点在线段 $PQ$ 上，最小距离为点 $A$ 到投影点的距离。

   - 当 $t < 0$ 时，投影点位于点 $P$ 的延长线上，此时最小距离为 $|AP|$。

   - 当 $t > 1$ 时，投影点位于点 $Q$ 的延长线上，此时最小距离为 $|AQ|$。

4. 计算最小距离，输出结果，保留三位小数。

## 参考代码

```cpp
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

namespace
{
auto calculate_distance(double_t x_1, double_t y_1, double_t x_2, double_t y_2) -> double_t
{
    return hypot(x_1 - x_2, y_1 - y_2);
}
} // namespace

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        double_t x_a, y_a;
        double_t x_p, y_p, x_q, y_q;
        cin >> x_a >> y_a >> x_p >> y_p >> x_q >> y_q;

        double_t dx = x_q - x_p;
        double_t dy = y_q - y_p;

        double_t distance;
        double_t t_program = ((x_a - x_p) * dx + (y_a - y_p) * dy) / (dx * dx + dy * dy);
        if (t_program < 0.0)
        {
            distance = calculate_distance(x_a, y_a, x_p, y_p);
        }
        else if (t_program > 1.0)
        {
            distance = calculate_distance(x_a, y_a, x_q, y_q);
        }
        else // Projection is on the line segment
        {
            double_t projection_x = x_p + (t_program * dx);
            double_t projection_y = y_p + (t_program * dy);
            distance = calculate_distance(x_a, y_a, projection_x, projection_y);
        }
        cout << fixed << setprecision(3) << distance << '\n';
    }

    return 0;
}
```
