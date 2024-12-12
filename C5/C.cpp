#include <cstdint>
#include <iostream>

using namespace std;

auto cross_product(int64_t x_1, int64_t y_1, int64_t x_2, int64_t y_2, int64_t x_3, int64_t y_3) -> int64_t
{
    return (x_2 - x_1) * (y_3 - y_1) - (x_3 - x_1) * (y_2 - y_1);
}

auto on_segment(int64_t x_1, int64_t y_1, int64_t x_2, int64_t y_2, int64_t x_3, int64_t y_3) -> bool
{
    return (min(x_1, x_2) <= x_3 && x_3 <= max(x_1, x_2) && min(y_1, y_2) <= y_3 && y_3 <= max(y_1, y_2));
}

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        int64_t x_p1, y_p1, x_q1, y_q1;
        int64_t x_p2, y_p2, x_q2, y_q2;
        cin >> x_p1 >> y_p1 >> x_q1 >> y_q1;
        cin >> x_p2 >> y_p2 >> x_q2 >> y_q2;
        int64_t d_1, d_2, d_3, d_4;
        d_1 = cross_product(x_p1, y_p1, x_q1, y_q1, x_p2, y_p2);
        d_2 = cross_product(x_p1, y_p1, x_q1, y_q1, x_q2, y_q2);
        d_3 = cross_product(x_p2, y_p2, x_q2, y_q2, x_p1, y_p1);
        d_4 = cross_product(x_p2, y_p2, x_q2, y_q2, x_q1, y_q1);
        // intersect
        if (((d_1 > 0 && d_2 < 0) || (d_1 < 0 && d_2 > 0)) && ((d_3 > 0 && d_4 < 0) || (d_3 < 0 && d_4 > 0)))
        {
            cout << "intersect\n";
            continue;
        }
        if (d_1 == 0 && on_segment(x_p1, y_p1, x_q1, y_q1, x_p2, y_p2))
        {
            cout << "intersect\n";
            continue;
        }
        if (d_2 == 0 && on_segment(x_p1, y_p1, x_q1, y_q1, x_q2, y_q2))
        {
            cout << "intersect\n";
            continue;
        }
        if (d_3 == 0 && on_segment(x_p2, y_p2, x_q2, y_q2, x_p1, y_p1))
        {
            cout << "intersect\n";
            continue;
        }
        if (d_4 == 0 && on_segment(x_p2, y_p2, x_q2, y_q2, x_q1, y_q1))
        {
            cout << "intersect\n";
            continue;
        }

        // parallel
        if ((y_q1 - y_p1) == 0 && (y_q2 - y_p2) == 0)
        {
            cout << "parallel\n";
            continue;
        }
        if ((x_q1 - x_p1) == 0 && (x_q2 - x_p2) == 0)
        {
            cout << "parallel\n";
            continue;
        }
        if ((y_q1 - y_p1) * (x_q2 - x_p2) == (y_q2 - y_p2) * (x_q1 - x_p1) && (y_q1 - y_p1) != 0 && (x_q1 - x_p1) != 0)
        {
            cout << "parallel\n";
            continue;
        }
        // disjoint
        cout << "neither\n";
    }

    return 0;
}
