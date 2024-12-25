#include <cstdint>
#include <iostream>

using namespace std;

auto main() -> int
{
    uint64_t T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        uint64_t n, l;
        cin >> n >> l;
        cout << n - 1 << '\n';
    }

    return 0;
}
