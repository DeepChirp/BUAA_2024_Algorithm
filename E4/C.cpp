#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct Edge
{
    uint64_t to;
    uint64_t weight;
};

namespace
{
auto dijkstra(uint64_t start, const vector<vector<Edge>> &graph) -> vector<uint64_t>
{
    vector<uint64_t> distance(graph.size(), UINT64_MAX);
    distance[start] = 0;
    priority_queue<pair<uint64_t, uint64_t>, vector<pair<uint64_t, uint64_t>>, greater<>> priority_queue;
    priority_queue.emplace(0, start);
    while (!priority_queue.empty())
    {
        auto [current_distance, u] = priority_queue.top();
        priority_queue.pop();
        if (current_distance > distance[u])
        {
            continue;
        }
        for (const auto &edge : graph[u])
        {
            if (distance[edge.to] > distance[u] + edge.weight)
            {
                distance[edge.to] = distance[u] + edge.weight;
                priority_queue.emplace(distance[edge.to], edge.to);
            }
        }
    }
    return distance;
}
} // namespace

auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        uint64_t n, m, k;
        cin >> n >> m >> k;
        vector<vector<Edge>> graph(n + 1);
        vector<uint64_t> print_store(k);
        for (size_t j = 0; j < k; j++)
        {
            cin >> print_store[j];
        }
        for (size_t j = 0; j < m; j++)
        {
            uint64_t from, to, weight;
            cin >> from >> to >> weight;
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight});
        }

        vector<uint64_t> distance_from_start = dijkstra(1, graph);
        vector<uint64_t> distance_from_end = dijkstra(n, graph);

        uint64_t min_distance = UINT64_MAX;
        for (const auto &p : print_store)
        {
            if (distance_from_start[p] != UINT64_MAX && distance_from_end[p] != UINT64_MAX)
            {
                uint64_t total_distance = distance_from_start[p] + distance_from_end[p];
                min_distance = min(min_distance, total_distance);
            }
        }

        if (min_distance == UINT64_MAX)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << min_distance << '\n';
        }
    }

    return 0;
}
