#include <cstdbool>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct Player
{
    bool is_out;
};

auto main() -> int
{
    uint64_t T;
    cin >> T;
    for (size_t i = 0; i < T; ++i)
    {
        uint64_t n, k;
        cin >> n >> k;
        vector<Player> players(n + 1);
        players.assign(n + 1, {false});
        for (size_t j = 1; j <= k; ++j)
        {
            uint64_t result = 0;
            for (size_t l = j + 1; l <= n; l += (j + 1))
            {
                if (!players[l].is_out)
                {
                    result++;
                    players[l].is_out = true;
                }
            }
            cout << result << ' ';
        }
        cout << '\n';
    }
}
