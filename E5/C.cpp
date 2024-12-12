#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

const uint64_t MAX_N = 100001;
const uint64_t MOD = 998244353;

auto main() -> int
{
    uint64_t n, m;
    cin >> n >> m;
    uint64_t l, r;
    cin >> l >> r;

    array<uint64_t, MAX_N> dp;
    dp.fill(0);
    dp.at(0) = 1;
    array<bool, MAX_N> is_leaf;
    is_leaf.fill(false);
    is_leaf.at(0) = true;
    for (size_t i = 0; i < m; i++)
    {
        uint64_t index;
        cin >> index;
        is_leaf.at(index) = true;
    }

    for (size_t i = 0; i <= n; i++)
    {
        if (is_leaf.at(i))
        {
            for (size_t j = l; j <= r && i + j <= n; j++)
            {
                dp.at(i + j) += dp.at(i) % MOD;
                dp.at(i + j) %= MOD;
            }
        }
    }

    cout << dp.at(n) << '\n';

    return 0;
}
