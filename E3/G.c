#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

int parent[MAXN], size[MAXN];

typedef struct
{
    int u, v, h;
} Edge;

int cmp(const void *a, const void *b)
{
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->h - e2->h;
}

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
    {
        if (size[fx] < size[fy])
        {
            parent[fx] = fy;
            size[fy] += size[fx];
        }
        else
        {
            parent[fy] = fx;
            size[fx] += size[fy];
        }
    }
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        Edge *edges = (Edge *)malloc(sizeof(Edge) * m);
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].h);
        qsort(edges, m, sizeof(Edge), cmp);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            unite(edges[i].u, edges[i].v);
            if (size[find(1)] == n)
            {
                ans = edges[i].h;
                break;
            }
        }
        printf("%d\n", ans);
        free(edges);
    }
    return 0;
}
