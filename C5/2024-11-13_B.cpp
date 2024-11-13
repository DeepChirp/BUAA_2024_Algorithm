#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>

#define EPSILON 1e-9

using namespace std;

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
        double_t length = dx * dx + dy * dy;
        double_t distance;

        if (length < EPSILON) // Line segment is a point
        {
            distance = sqrt((x_a - x_p) * (x_a - x_p) + (y_a - y_p) * (y_a - y_p));
        }
        else
        {
            double_t t_param = ((x_a - x_p) * dx + (y_a - y_p) * dy) / length;
            if (t_param < 0.0) // Projection is outside the line segment
            {
                distance = sqrt((x_a - x_p) * (x_a - x_p) + (y_a - y_p) * (y_a - y_p));
            }
            else if (t_param > 1.0) // Projection is outside the line segment
            {
                distance = sqrt((x_a - x_q) * (x_a - x_q) + (y_a - y_q) * (y_a - y_q));
            }
            else
            {
                double_t proj_x = x_p + t_param * dx;
                double_t proj_y = y_p + t_param * dy;
                distance = sqrt((x_a - proj_x) * (x_a - proj_x) + (y_a - proj_y) * (y_a - proj_y));
            }
        }
        cout << fixed << setprecision(3) << distance << '\n';
    }

    return 0;
}
