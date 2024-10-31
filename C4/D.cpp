#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        int length;
        std::cin >> length;
        pq.push(length);
    }

    long long total_cost = 0;
    while (pq.size() > 1)
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long cost = first + second;
        total_cost += 2 * cost;
        pq.push(cost);
    }

    std::cout << total_cost << std::endl;
    return 0;
}