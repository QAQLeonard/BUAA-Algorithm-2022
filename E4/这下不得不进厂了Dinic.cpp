#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const long long N = 10010, M = 200010, INF = 1e8;

long long n, m, S, T;
long long h[N], e[M], f[M], ne[M], idx;
long long q[N], d[N], cur[N];

void add(long long a, long long b, long long c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs()
{
    long long hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while (hh <= tt)
    {
        long long t = q[hh++];
        for (long long i = h[t]; ~i; i = ne[i])
        {
            long long ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T)
                    return true;
                q[++tt] = ver;
            }
        }
    }
    return false;
}

long long find(long long u, long long limit)
{
    if (u == T)
        return limit;
    long long flow = 0;
    for (long long i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i; // 当前弧优化
        long long ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            long long t = find(ver, min(f[i], limit - flow));
            if (!t)
                d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

long long dinic()
{
    long long r = 0, flow;
    while (bfs())
        while ((flow = find(S, INF)))
            r += flow;
    return r;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        memset(e, 0, sizeof e);
        memset(ne, 0, sizeof ne);
        memset(q, 0, sizeof q);
        memset(d, 0, sizeof d);
        memset(cur, 0, sizeof cur);
        memset(f, 0, sizeof f);
        scanf("%lld%lld%lld%lld", &n, &m, &S, &T);
        memset(h, -1, sizeof h);
        while (m--)
        {
            long long a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            add(a, b, c);
        }

        printf("%lld\n", dinic());
    }

    return 0;
}
