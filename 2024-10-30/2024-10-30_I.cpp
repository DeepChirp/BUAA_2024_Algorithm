#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
    int to;
    unsigned long long time;
};

void dijkstra(int s, vector<vector<Edge>> &graph, vector<unsigned long long> &dist);

int main()
{
    int n, m, s;
    unsigned long long t;
    cin >> n >> m >> s >> t;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        unsigned long long ti;
        cin >> x >> y >> ti;
        graph[x].push_back({y, ti});
        graph[y].push_back({x, ti});
    }

    vector<unsigned long long> dist(n + 1, ULLONG_MAX);
    dijkstra(s, graph, dist);

    vector<pair<int, long long>> unacceptable;
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
        {
            if (dist[i] > t)
            {
                unacceptable.push_back({i, dist[i]});
            }
            else if (dist[i] == ULLONG_MAX)
            {
                unacceptable.push_back({i, -1});
            }
        }
    }

    cout << unacceptable.size() << endl;
    for (const auto &[node, time] : unacceptable)
    {
        cout << node << " " << time << endl;
    }

    return 0;
}

void dijkstra(int s, vector<vector<Edge>> &graph, vector<unsigned long long> &dist)
{
    priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (const auto &edge : graph[u])
        {
            int v = edge.to;
            unsigned long long time = edge.time;
            if (dist[u] + time < dist[v])
            {
                dist[v] = dist[u] + time;
                pq.push({dist[v], v});
            }
        }
    }
}
