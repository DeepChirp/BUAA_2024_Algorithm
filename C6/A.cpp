#include <cstdint>
#include <iostream>
#include <vector>

struct Edge
{
    uint64_t from;
    uint64_t to;
    uint64_t weight;
};

using namespace std;

auto main() -> int
{
    uint64_t n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph((2 * m) + 1);
    for (size_t i = 0; i < m; i++)
    {
        uint64_t u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({u, v, w});
        graph[v].push_back({v, u, w});
    }

    // Prim's algorithm
    vector<bool> visited(n + 1);
    vector<uint64_t> dist(n + 1, UINT64_MAX);
    dist[1] = 0;
    uint64_t result = 0;
    for (size_t i = 1; i <= n; i++)
    {
        uint64_t u = 0;
        for (size_t j = 1; j <= n; j++)
        {
            if (!visited[j] && (u == 0 || dist[j] < dist[u]))
            {
                u = j;
            }
        }
        visited[u] = true;
        result += dist[u];
        for (auto &j : graph[u])
        {
            uint64_t v = j.to;
            uint64_t w = j.weight;
            if (!visited[v] && w < dist[v])
            {
                dist[v] = w;
            }
        }
    }
    cout << result << '\n';

    return 0;
}
