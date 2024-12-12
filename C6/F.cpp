#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

auto main() -> int
{
    uint64_t n;
    cin >> n;
    int64_t area = 0;
    int64_t x_0, y_0;
    cin >> x_0 >> y_0;
    int64_t x_pre = x_0, y_pre = y_0;
    for (size_t i = 0; i < n - 1; i++)
    {
        int64_t x, y;
        cin >> x >> y;
        area += x_pre * y - y_pre * x;
        x_pre = x;
        y_pre = y;
    }
    area += x_pre * y_0 - y_pre * x_0;
    cout << area << '\n';

    return 0;
}
