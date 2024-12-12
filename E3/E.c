#include <stdio.h>

#define MAXN 10005
int T, n, m;
int head[MAXN], to[MAXN * 2], next[MAXN * 2], cnt;
int vis[MAXN], stack[MAXN], top;
int order[MAXN], idx;
int far[MAXN];

void add_edge(int u, int v)
{
    cnt++;
    to[cnt] = v;
    next[cnt] = head[u];
    head[u] = cnt;
}

void dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = next[i])
    {
        int v = to[i];
        if (!vis[v])
            dfs(v);
    }
    order[++idx] = u;
}

int main(void)
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        cnt = idx = top = 0;
        for (int i = 1; i <= n; i++)
        {
            head[i] = vis[i] = far[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add_edge(u, v);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs(i);
        }
        int semi = 1;
        for (int i = n; i >= 1; i--)
        {
            int u = order[i];
            far[u] = u;
            for (int j = head[u]; j; j = next[j])
            {
                int v = to[j];
                if (far[v] > far[u])
                    far[u] = far[v];
            }
            if (i < n && far[u] < order[i + 1])
            {
                semi = 0;
                break;
            }
        }
        if (semi)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
