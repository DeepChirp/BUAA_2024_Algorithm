#include <cstdint>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_NUM = 805;
const int64_t INF = 1e18;

struct Edge
{
    int to, rev;
    int64_t cap;
};

vector<Edge> G[MAX_NUM];
int level[MAX_NUM];
int iter[MAX_NUM];

void add_edge(int from, int to, int64_t cap)
{
    G[from].push_back({to, (int)G[to].size(), cap});
    G[to].push_back({from, (int)G[from].size() - 1, 0});
}

auto bfs(int s, int t) -> bool
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (const auto &e : G[v])
        {
            if (e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

auto dfs(int v, int t, int64_t f) -> int64_t
{
    if (v == t)
    {
        return f;
    }
    for (int &i = iter[v]; i < G[v].size(); ++i)
    {
        Edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            int64_t d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

auto max_flow(int s, int t) -> int64_t
{
    int64_t flow = 0;
    while (bfs(s, t))
    {
        memset(iter, 0, sizeof(iter));
        int64_t f;
        while ((f = dfs(s, t, INF)) > 0)
        {
            flow += f;
        }
    }
    return flow;
}

auto main() -> int
{
    int n;
    cin >> n;
    vector<int> a(n), p(n), b(n), q(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    for (auto &x : p)
    {
        cin >> x;
    }
    for (auto &x : b)
    {
        cin >> x;
    }
    for (auto &x : q)
    {
        cin >> x;
    }

    for (int i = 0; i < 2 * n + 2; ++i)
    {
        G[i].clear();
    }

    int source = 2 * n;
    int sink = (2 * n) + 1;

    for (int i = 0; i < n; ++i)
    {
        add_edge(source, i, 1);
        add_edge(n + i, sink, 1);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i] >= q[j] && b[j] >= p[i])
            {
                add_edge(i, n + j, 1);
            }
        }
    }

    cout << max_flow(source, sink) << '\n';

    return 0;
}
