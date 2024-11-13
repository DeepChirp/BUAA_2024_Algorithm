#include <cstddef>
#include <cstdint>
#include <iostream>

using namespace std;

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        uint64_t n;
        cin >> n;
        int64_t first_x, first_y;
        cin >> first_x >> first_y;
        int64_t second_x, second_y;
        cin >> second_x >> second_y;
        bool is_collinear = true;
        for (size_t j = 0; j < n - 2; j++)
        {
            int64_t x, y;
            cin >> x >> y;
            if (is_collinear && (x - first_x) * (second_y - first_y) != (y - first_y) * (second_x - first_x))
            {
                is_collinear = false;
            }
        }
        cout << (is_collinear ? "boo how! boo how!" : "how?") << '\n';
    }

    return 0;
}
