#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 5e5 + 10;

struct node
{
    int x, y, z;
} edge[maxn];

bool cmp(node a, node b)
{
    return a.z < b.z;
}

int fa[maxn];

int n, m;

int u, v, w;

long long sum;

int get(int x)
{
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z);
    }
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
    }
    sort(edge + 1, edge + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        int x = get(edge[i].x);
        int y = get(edge[i].y);
        if (x == y)
            continue;
        fa[y] = x;
        sum += edge[i].z;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == fa[i])
            ans++;
    }
        printf("%lld\n", sum);
    return 0;
}