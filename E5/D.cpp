// 大根堆和小根堆

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>

using namespace std;

auto main() -> int
{
    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        uint64_t n;
        cin >> n;
        vector<uint64_t> result;
        priority_queue<uint64_t> max_heap;
        priority_queue<uint64_t, vector<uint64_t>, greater<>> min_heap;
        for (size_t j = 1; j <= n; j++)
        {
            uint64_t x;
            cin >> x;
            if (max_heap.empty() || x <= max_heap.top())
            {
                max_heap.push(x);
            }
            else
            {
                min_heap.push(x);
            }
            if (max_heap.size() > min_heap.size() + 1)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else if (min_heap.size() > max_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            // 当前缀长度为奇数时，记录中位数
            if (j % 2 == 1)
            {
                result.push_back(max_heap.top());
            }
        }
        for (size_t j = 0; j < result.size(); j++)
        {
            cout << result[j];
            if (j != result.size() - 1)
            {
                cout << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
