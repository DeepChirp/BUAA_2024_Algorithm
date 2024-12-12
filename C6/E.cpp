#include <cstdint>
#include <iostream>

using namespace std;

auto extended_euclidean_algorithm(int64_t a, int64_t b, int64_t &x, int64_t &y) -> int64_t
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int64_t gcd = extended_euclidean_algorithm(b, a % b, x, y);
    int64_t temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

auto main() -> int
{
    int64_t a, b;
    cin >> a >> b;

    int64_t x, y;
    extended_euclidean_algorithm(a, b, x, y);
    x = (x % b + b) % b;
    cout << x << '\n';

    return 0;
}
