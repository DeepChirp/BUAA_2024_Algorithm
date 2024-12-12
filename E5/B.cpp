#include <algorithm>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

auto main() -> int
{
    uint64_t n, m, q;
    cin >> n >> m >> q;

    vector<vector<uint64_t>> dist(n + 1, vector<uint64_t>(n + 1, UINT64_MAX));
    vector<tuple<uint64_t, uint64_t, uint64_t>> edges(m + 1);
    for (size_t i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (size_t i = 1; i <= m; i++)
    {
        uint64_t u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = dist[u][v];
        edges[i] = {u, v, w};
    }
    // Floyd-Warshall
    for (size_t k = 1; k <= n; k++)
    {
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= n; j++)
            {
                if (dist[i][k] != UINT64_MAX && dist[k][j] != UINT64_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (size_t i = 0; i < q; i++)
    {
        uint64_t s, t, k;
        cin >> s >> t >> k;
        uint64_t u = get<0>(edges[k]);
        uint64_t v = get<1>(edges[k]);
        uint64_t w = get<2>(edges[k]);
        uint64_t via_u = UINT64_MAX, via_v = UINT64_MAX;
        if (dist[s][u] != UINT64_MAX && dist[v][t] != UINT64_MAX)
        {
            via_u = dist[s][u] + w + dist[v][t];
        }
        if (dist[s][v] != UINT64_MAX && dist[u][t] != UINT64_MAX)
        {
            via_v = dist[s][v] + w + dist[u][t];
        }
        uint64_t shortest = dist[s][t];
        uint64_t min_via = min(via_u, via_v);
        if (shortest == min_via && shortest != UINT64_MAX)
        {
            cout << "Yes" << '\n';
        }
        else
        {
            cout << "No" << '\n';
        }
    }
    return 0;
}
