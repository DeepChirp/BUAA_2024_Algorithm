// ref: https://oi-wiki.org/geometry/nearest-points/

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point
{
    int64_t x, y;
};

struct PairHash
{
    auto operator()(const pair<int64_t, int64_t> &p) const -> size_t
    {
        return hash<int64_t>()(p.first) * 1000000007 + hash<int64_t>()(p.second);
    }
};

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t n, q;
    cin >> n >> q;
    int R = 10;
    unordered_map<pair<int64_t, int64_t>, vector<Point>, PairHash> grid;
    for (size_t i = 0; i < n; i++)
    {
        Point p{};
        cin >> p.x >> p.y;
        int64_t g_x = p.x / R;
        int64_t g_y = p.y / R;
        grid[{g_x, g_y}].push_back(p);
    }
    while ((q--) != 0U)
    {
        Point pos{};
        uint64_t radius;
        cin >> pos.x >> pos.y >> radius;
        int64_t g_x = pos.x / R;
        int64_t g_y = pos.y / R;
        uint64_t count = 0;
        for (int64_t dx = -1; dx <= 1; dx++)
        {
            for (int64_t dy = -1; dy <= 1; dy++)
            {
                auto it = grid.find({g_x + dx, g_y + dy});
                if (it != grid.end())
                {
                    for (auto &p : it->second)
                    {
                        int64_t dist_sq = (p.x - pos.x) * (p.x - pos.x) + (p.y - pos.y) * (p.y - pos.y);
                        if (dist_sq <= radius * radius)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
