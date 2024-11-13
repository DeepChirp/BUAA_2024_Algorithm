#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

#define SUM 5

using namespace std;

struct Point
{
    double x;
    double y;
};

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        double min_distance = std::numeric_limits<double>::min();
        std::vector<Point> points(SUM);
        for (size_t j = 0; j < SUM; j++)
        {
            cin >> points[j].x >> points[j].y;
        }

        // select three points to form a circle
        for (size_t j = 0; j < SUM; j++)
        {
            for (size_t k = j + 1; k < SUM; k++)
            {
                for (size_t l = k + 1; l < SUM; l++)
                {
                    // calculate circumcircle
                    double A = points[k].x - points[j].x;
                    double B = points[k].y - points[j].y;
                    double C = points[l].x - points[j].x;
                    double D = points[l].y - points[j].y;
                    double E = A * (points[j].x + points[k].x) + B * (points[j].y + points[k].y);
                    double F = C * (points[j].x + points[l].x) + D * (points[j].y + points[l].y);
                    double det = 2 * (A * D - B * C);
                    double center_x = (D * E - B * F) / det;
                    double center_y = (A * F - C * E) / det;

                    // calculate radius squared
                    double radius_sq = (center_x - points[j].x) * (center_x - points[j].x) + (center_y - points[j].y) * (center_y - points[j].y);

                    // remaining two points
                    std::vector<Point> remaining;
                    for (size_t m = 0; m < SUM; m++)
                    {
                        if (m != j && m != k && m != l)
                        {
                            remaining.push_back(points[m]);
                        }
                    }

                    // line coefficients: ax + by + c = 0
                    double a = remaining[1].y - remaining[0].y;
                    double b = remaining[0].x - remaining[1].x;
                    double c = remaining[1].x * remaining[0].y - remaining[0].x * remaining[1].y;
                    double dist = std::abs(a * center_x + b * center_y + c) / std::sqrt(a * a + b * b);

                    double current_min = std::max(0.0, dist - std::sqrt(radius_sq));
                    if (current_min > min_distance)
                    {
                        min_distance = current_min;
                    }
                }
            }
        }

        cout << fixed << setprecision(3) << min_distance << '\n';
    }

    return 0;
}
