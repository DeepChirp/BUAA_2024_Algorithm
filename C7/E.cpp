#include <algorithm>
#include <cstdbool>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct Activity
{
    uint64_t start;
    uint64_t end;
};

auto main() -> int
{
    uint64_t T;
    cin >> T;
    for (size_t i = 0; i < T; ++i)
    {
        uint64_t n, k;
        cin >> n >> k;
        vector<Activity> activities(k);
        for (size_t j = 0; j < k; ++j)
        {
            cin >> activities.at(j).start >> activities.at(j).end;
        }
        sort(activities.begin(), activities.end(), [](const Activity &a, const Activity &b) -> bool
             { return a.end < b.end; });
        uint64_t current_index = 0;
        uint64_t result = 0;
        for (size_t j = 0; j < k; j++)
        {
            if (activities[j].start > current_index)
            {
                result++;
                current_index = activities[j].end;
            }
        }
        cout << result << '\n';
    }
}
