#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        uint64_t n, m;
        cin >> n >> m;
        vector<uint64_t> dp(m + 1, 0);
        for (size_t j = 0; j < n; j++)
        {
            uint64_t k, c, d;
            cin >> k >> c >> d;

            uint64_t count = k;
            for (size_t num = 1; count > 0; num <<= 1)
            {
                uint64_t actual = min(num, count);
                count -= actual;
                uint64_t total_cost = actual * c;
                uint64_t total_value = actual * d;

                for (size_t p = m; p >= total_cost; p--)
                {
                    dp[p] = max(dp[p], dp[p - total_cost] + total_value);
                }
            }
        }
        cout << dp[m] << '\n';
    }

    return 0;
}
