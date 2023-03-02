#include <iostream>
#include <cstring>
using namespace std;

const int N = 505, M = 10005, MMAX = 1000000000;

int n, m, q, bbegin, eend, k;

long long int dis[N], backup[N];

struct Edge
{ // Bellman-Ford 每次只需要遍历所有边，不用管某个点连了哪些边，用结构体即可
    int x, y, w;
} edges[3 * M];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &edges[2 * i - 1].x, &edges[2 * i - 1].y, &edges[2 * i - 1].w);
        edges[2 * i].x = edges[2 * i - 1].y;
        edges[2 * i].y = edges[2 * i - 1].x;
        edges[2 * i].w = edges[2 * i - 1].w;
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", &bbegin, &eend, &k);
        memset(dis, MMAX, sizeof dis);
        dis[bbegin] = 0;

        for (int i = 1; i <= k; i++)
        {
            memcpy(backup, dis, sizeof dis); // dis 复制到 backup
            for (int j = 1; j <= 2 * m; j++)
            {
                int x = edges[j].x, y = edges[j].y, w = edges[j].w;
                if (backup[x] < MMAX)
                    dis[y] = min(dis[y], backup[x] + w);
            }
            // for(int i=1;i<=n;i++)
            //     cout<<dis[i]<<" ";
        }

        if (dis[eend] =MMAX)
            printf("-1\n");
        else
            printf("%d\n", dis[eend]);
    }

    return 0;
}
