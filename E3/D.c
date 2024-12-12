#include <stdint.h>
#include <stdio.h>

#define MAX_NUM 100005

int n;
int ans = 0;
int color[MAX_NUM];
int head[MAX_NUM], to[MAX_NUM * 2], next[MAX_NUM * 2], sum;

void add_edge(int u, int v)
{
    sum++;
    to[sum] = v;
    next[sum] = head[u];
    head[u] = sum;
}

int dfs(uint64_t u, int parent)
{
    int cnt = (color[u] == 1) ? 1 : 0;
    for (int i = head[u]; i; i = next[i])
    {
        int v = to[i];
        if (v != parent)
        {
            cnt += dfs(v, u);
        }
    }
    if (cnt > 0 && color[u] == 0)
    {
        ans++;
    }
    return cnt;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    uint64_t root = 1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            root = i;
            break;
        }
    }
    dfs(root, 0);
    printf("%d\n", ans);
    return 0;
}
