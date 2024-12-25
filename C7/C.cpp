#include <cstdbool>
#include <cstdint>
#include <iostream>

using namespace std;

auto main() -> int
{
    uint64_t T;
    cin >> T;
    for (size_t i = 0; i < T; ++i)
    {
        uint64_t n;
        cin >> n;
        uint64_t previous_num = 1;
        uint64_t max_num = 0;
        uint64_t current_num;
        bool result = true;
        for (size_t j = 0; j < n; j++)
        {
            cin >> current_num;
            max_num = max(max_num, current_num);
            if (current_num < max_num && current_num > previous_num)
            {
                result = false;
            }
            previous_num = current_num;
        }
        if (result)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
