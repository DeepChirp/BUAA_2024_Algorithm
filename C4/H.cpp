#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        in_degree[v]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        result.push_back(node);

        for (int neighbor : adj_list[node])
        {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0)
            {
                pq.push(neighbor);
            }
        }
    }

    for (int i = 0; i < (int)result.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
