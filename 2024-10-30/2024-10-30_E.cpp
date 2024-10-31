#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 1e13;

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long long>> dist(n, std::vector<long long>(n, INF));

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        dist[u - 1][v - 1] = std::min(dist[u - 1][v - 1], (long long)w);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        std::cin >> u >> v;
        if (dist[u - 1][v - 1] == INF)
        {
            std::cout << -1 << std::endl;
        }
        else
        {
            std::cout << dist[u - 1][v - 1] << std::endl;
        }
    }

    return 0;
}
